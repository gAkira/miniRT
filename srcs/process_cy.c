/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 21:45:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    allocate_in_scene
** Description:
**    Create an array of addresses of cylinders (cy)
**    Create each instance of cylinder in its respective index
** Params:
**    char ***cy -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	allocate_in_scene(char ***cy, t_scene *scene)
{
	int	i;

	i = 0;
	while (cy[i])
		i++;
	if (!(scene->cy = (t_cy**)ft_calloc(i + 1, sizeof(t_cy*))))
		return (false);
	allocate_flag(&(scene->allocation), CY_MASK);
	i = 0;
	while (cy[i])
		if (!(scene->cy[i++] = (t_cy*)ft_calloc(1, sizeof(t_cy))))
			return (false);
	return (true);
}

/*
** [STATIC] Function name:
**    put_in_scene
** Description:
**    Put data into scene instance
** Params:
**    char ***cy -> array of tables made with ft_split (see libft)
**    char ***params -> parameters parsed by params_in_scene function
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which allocate
** Return:
**    ---
*/

static void	put_in_scene(char ***cy, char ***params, t_scene *scene, int i)
{
	scene->cy[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->cy[i]->dir = mx_vector(ft_atof(params[1][0]), \
								ft_atof(params[1][1]), \
								ft_atof(params[1][2]));
	scene->cy[i]->diam = ft_atof(cy[i][3]);
	scene->cy[i]->height = ft_atof(cy[i][4]);
	scene->cy[i]->mat.color = mx_vector(ft_atof(params[2][0]) / 255.0, \
								ft_atof(params[2][1]) / 255.0, \
								ft_atof(params[2][2]) / 255.0);
	scene->cy[i]->mat.ambient = 0.1;
	scene->cy[i]->mat.diffuse = 0.9;
	scene->cy[i]->mat.specular = 0.9;
	scene->cy[i]->mat.shininess = 200.0;
}

/*
** [STATIC] Function name:
**    params_in_scene
** Description:
**    Parse params
**    Call put_in_scene
**    Free params
** Params:
**    char ***cy -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which perform operations
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	params_in_scene(char ***cy, t_scene *scene, int i)
{
	char **params[3];

	ft_bzero(&params, 3 * sizeof(char**));
	if (!(params[0] = ft_split(cy[i][1], ',')) || \
		!(params[1] = ft_split(cy[i][2], ',')) || \
		!(params[2] = ft_split(cy[i][5], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		ft_free_split(&(params[2]));
		return (false);
	}
	put_in_scene(cy, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	ft_free_split(&(params[2]));
	return (true);
}

/*
** Function name:
**    process_cy
** Description:
**    If char ***cy is NULL, it just returns NO_ERROR
**    Process each cylinder (cy) arguments and parameters
**    Allocate each object correctly and set its flag
** Params:
**    char ***cy -> array of tables (made with ft_split - more info in libft)
**                  each index of the first array (cy[index1]) is a line
**                  (i.e. a different cylinder) of the file. At the
**                  second index (cy[index1][index2]) is a word (string) of
**                  the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error		process_cy(char ***cy, t_scene *scene)
{
	int		i;

	if (!cy)
		return (NO_ERROR);
	if (!allocate_in_scene(cy, scene))
		return (NO_MEMORY);
	i = 0;
	while (cy[i])
		if (!params_in_scene(cy, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
