/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 02:55:17 by galves-d         ###   ########.fr       */
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
	scene->c[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->c[i]->dir = mx_vector(ft_atof(params[1][0]), \
								ft_atof(params[1][1]), \
								ft_atof(params[1][2]));
	scene->c[i]->fov = ft_atoi(c[i][3]);
	scene->c[i]->canvas = create_canvas(scene->res.x, scene->res.y);
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
