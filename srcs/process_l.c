/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 22:51:08 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    allocate_in_scene
** Description:
**    Create an array of addresses of lights (l)
**    Create each instance of light in its respective index
** Params:
**    char ***l -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	allocate_in_scene(char ***l, t_scene *scene)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	if (!(scene->l = (t_l**)ft_calloc(i + 1, sizeof(t_l*))))
		return (false);
	allocate_flag(&(scene->allocation), L_MASK);
	i = 0;
	while (l[i])
		if (!(scene->l[i++] = (t_l*)ft_calloc(1, sizeof(t_l))))
			return (false);
	return (true);
}

/*
** [STATIC] Function name:
**    put_in_scene
** Description:
**    Put data into scene instance
** Params:
**    char ***l -> array of tables made with ft_split (see libft)
**    char ***params -> parameters parsed by params_in_scene function
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which allocate
** Return:
**    ---
*/

static void	put_in_scene(char ***l, char ***params, t_scene *scene, int i)
{
	scene->l[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->l[i]->ratio = ft_atof(l[i][2]);
	scene->l[i]->color = mx_vector(ft_atoi(params[1][0]), \
								ft_atoi(params[1][1]), \
								ft_atoi(params[1][2]));
}

/*
** [STATIC] Function name:
**    params_in_scene
** Description:
**    Parse params
**    Call put_in_scene
**    Free params
** Params:
**    char ***l -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which perform operations
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	params_in_scene(char ***l, t_scene *scene, int i)
{
	char **params[2];

	ft_bzero(&params, 2 * sizeof(char**));
	if (!(params[0] = ft_split(l[i][1], ',')) || \
		!(params[1] = ft_split(l[i][3], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		return (false);
	}
	put_in_scene(l, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	return (true);
}

/*
** Function name:
**    process_l
** Description:
**    If char ***l is NULL, it just returns NO_ERROR
**    Process each lights (l) arguments and parameters
**    Allocate each object correctly and set its flag
** Params:
**    char ***l -> array of tables (made with ft_split - more info in libft)
**                 each index of the first array (l[index1]) is a line
**                 (i.e. a different light) of the file. At the
**                 second index (l[index1][index2]) is a word (string) of
**                 the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error		process_l(char ***l, t_scene *scene)
{
	int		i;

	if (!l)
		return (NO_ERROR);
	if (!allocate_in_scene(l, scene))
		return (NO_MEMORY);
	i = 0;
	while (l[i])
		if (!params_in_scene(l, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
