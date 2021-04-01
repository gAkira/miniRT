/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 21:02:44 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    allocate_in_scene
** Description:
**    Create an array of addresses of triangles (tr)
**    Create each instance of triangle in its respective index
** Params:
**    char ***tr -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	allocate_in_scene(char ***tr, t_scene *scene)
{
	int	i;

	i = 0;
	while (tr[i])
		i++;
	if (!(scene->tr = (t_tr**)ft_calloc(i + 1, sizeof(t_tr*))))
		return (false);
	allocate_flag(&(scene->allocation), TR_MASK);
	i = 0;
	while (tr[i])
		if (!(scene->tr[i++] = (t_tr*)ft_calloc(1, sizeof(t_tr))))
			return (false);
	return (true);
}

/*
** [STATIC] Function name:
**    put_in_scene
** Description:
**    Put data into scene instance
** Params:
**    char ***tr -> array of tables made with ft_split (see libft)
**    char ***params -> parameters parsed by params_in_scene function
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which allocate
** Return:
**    ---
*/

static void	put_in_scene(char ***tr, char ***params, t_scene *scene, int i)
{
	(void)tr;
	scene->tr[i]->coord[0] = mx_point(ft_atof(params[0][0]), \
									ft_atof(params[0][1]), \
									ft_atof(params[0][2]));
	scene->tr[i]->coord[1] = mx_point(ft_atof(params[1][0]), \
									ft_atof(params[1][1]), \
									ft_atof(params[1][2]));
	scene->tr[i]->coord[2] = mx_point(ft_atof(params[2][0]), \
									ft_atof(params[2][1]), \
									ft_atof(params[2][2]));
	scene->tr[i]->color = mx_vector(ft_atof(params[3][0]) / 255.0, \
									ft_atof(params[3][1]) / 255.0, \
									ft_atof(params[3][2]) / 255.0);
}

/*
** [STATIC] Function name:
**    params_in_scene
** Description:
**    Parse params
**    Call put_in_scene
**    Free params
** Params:
**    char ***tr -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which perform operations
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	params_in_scene(char ***tr, t_scene *scene, int i)
{
	char **params[4];

	ft_bzero(&params, 4 * sizeof(char**));
	if (!(params[0] = ft_split(tr[i][1], ',')) || \
		!(params[1] = ft_split(tr[i][2], ',')) || \
		!(params[2] = ft_split(tr[i][3], ',')) || \
		!(params[3] = ft_split(tr[i][4], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		ft_free_split(&(params[2]));
		ft_free_split(&(params[3]));
		return (false);
	}
	put_in_scene(tr, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	ft_free_split(&(params[2]));
	ft_free_split(&(params[3]));
	return (true);
}

/*
** Function name:
**    process_tr
** Description:
**    If char ***tr is NULL, it just returns NO_ERROR
**    Process each triangle (tr) arguments and parameters
**    Allocate each object correctly and set its flag
** Params:
**    char ***tr -> array of tables (made with ft_split - more info in libft)
**                  each index of the first array (tr[index1]) is a line
**                  (i.e. a different triangle) of the file. At the
**                  second index (tr[index1][index2]) is a word (string) of
**                  the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error		process_tr(char ***tr, t_scene *scene)
{
	int		i;

	if (!tr)
		return (NO_ERROR);
	if (!allocate_in_scene(tr, scene))
		return (NO_MEMORY);
	i = 0;
	while (tr[i])
		if (!params_in_scene(tr, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
