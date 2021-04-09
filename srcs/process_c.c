/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/09 00:17:43 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    allocate_in_scene
** Description:
**    Create an array of addresses of cameras (c)
**    Create each instance of cam in its respective index
** Params:
**    char ***c -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	allocate_in_scene(char ***c, t_scene *scene)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	if (!(scene->c = (t_c**)ft_calloc(i + 1, sizeof(t_c*))))
		return (false);
	allocate_flag(&(scene->allocation), C_MASK);
	i = 0;
	while (c[i])
		if (!(scene->c[i++] = (t_c*)ft_calloc(1, sizeof(t_c))))
			return (false);
	return (true);
}

/*
** [STATIC] Function name:
**    put_in_scene
** Description:
**    Put data into scene instance
** Params:
**    char ***c -> array of tables made with ft_split (see libft)
**    char ***params -> parameters parsed by params_in_scene function
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which allocate
** Return:
**    ---
*/

static void	put_in_scene(char ***c, char ***params, t_scene *scene, int i)
{
	double	half_view;
	double	aspect;

	scene->c[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->c[i]->dir = mx_vector(ft_atof(params[1][0]), \
								ft_atof(params[1][1]), \
								ft_atof(params[1][2]));
	scene->c[i]->fov = ft_atof(c[i][3]);
	scene->c[i]->canvas = create_canvas(scene->res.x, scene->res.y);
	half_view = tan((scene->c[i]->fov / 180.0 * M_PI) / 2.0);
	aspect = (double)scene->res.x / (double)scene->res.y;
	if (aspect > 1.0 || mx_equal(aspect, 1.0))
	{
		scene->c[i]->half_width = half_view;
		scene->c[i]->half_height = half_view / aspect;
	}
	else
	{
		scene->c[i]->half_width = half_view * aspect;
		scene->c[i]->half_width = half_view;
	}
	scene->c[i]->pixel_size = (scene->c[i]->half_width * 2) / scene->res.x;
}

/*
** [STATIC] Function name:
**    set_transform
** Description:
**    Set the transform matrix accordingly
** Params:
**    t_c *c -> object in which put the respective transformation
** Return:
**    ---
*/

static void	set_transform(t_c *c)
{
	c->transform = mx_multiply(\
						mx_translate(\
							c->coord.pos[0], \
							c->coord.pos[1], \
							c->coord.pos[2]), \
						mx_multiply(\
							mx_yrotate(\
								acos(\
									c->dir.pos[2] \
									/ sqrt(\
										pow(c->dir.pos[0], 2) \
										+ pow(c->dir.pos[1], 2) \
										+ pow(c->dir.pos[2], 2)))), \
							mx_zrotate(\
								atan(\
									c->dir.pos[1] \
									/ c->dir.pos[0]))));
	c->inv_transform = mx_inv(c->transform);
}

/*
** [STATIC] Function name:
**    params_in_scene
** Description:
**    Parse params
**    Call put_in_scene
**    Free params
** Params:
**    char ***c -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which perform operations
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	params_in_scene(char ***c, t_scene *scene, int i)
{
	char	**params[2];

	ft_bzero(&params, 2 * sizeof(char**));
	if (!(params[0] = ft_split(c[i][1], ',')) || \
		!(params[1] = ft_split(c[i][2], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		return (false);
	}
	put_in_scene(c, params, scene, i);
	set_transform(scene->c[i]);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	if (!scene->c[i]->canvas)
		return (false);
	return (true);
}

/*
** Function name:
**    process_c
** Description:
**    If char ***c is NULL, it just returns NO_ERROR
**    Process each camera (c) arguments and parameters
**    Allocate each object correctly and set its flag
** Params:
**    char ***c -> array of tables (made with ft_split - more info in libft)
**                 each index of the first array (c[index1]) is a line
**                 (i.e. a different camera) of the file. At the
**                 second index (c[index1][index2]) is a word (string) of
**                 the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error		process_c(char ***c, t_scene *scene)
{
	int		i;

	if (!c)
		return (NO_ERROR);
	if (!allocate_in_scene(c, scene))
		return (NO_MEMORY);
	i = 0;
	while (c[i])
		if (!params_in_scene(c, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
