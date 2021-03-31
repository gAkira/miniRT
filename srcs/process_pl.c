/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 23:07:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    allocate_in_scene
** Description:
**    Create an array of addresses of planes (pl)
**    Create each instance of plane in its respective index
** Params:
**    char ***pl -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	allocate_in_scene(char ***pl, t_scene *scene)
{
	int	i;

	i = 0;
	while (pl[i])
		i++;
	if (!(scene->pl = (t_pl**)ft_calloc(i + 1, sizeof(t_pl*))))
		return (false);
	allocate_flag(&(scene->allocation), PL_MASK);
	i = 0;
	while (pl[i])
		if (!(scene->pl[i++] = (t_pl*)ft_calloc(1, sizeof(t_pl))))
			return (false);
	return (true);
}

/*
** [STATIC] Function name:
**    put_in_scene
** Description:
**    Put data into scene instance
** Params:
**    char ***pl -> array of tables made with ft_split (see libft)
**    char ***params -> parameters parsed by params_in_scene function
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which allocate
** Return:
**    ---
*/

static void	put_in_scene(char ***pl, char ***params, t_scene *scene, int i)
{
	(void)pl;
	scene->pl[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->pl[i]->dir = mx_vector(ft_atof(params[1][0]), \
								ft_atof(params[1][1]), \
								ft_atof(params[1][2]));
	scene->pl[i]->color = mx_vector(ft_atoi(params[2][0]), \
								ft_atoi(params[2][1]), \
								ft_atoi(params[2][2]));
}

/*
** [STATIC] Function name:
**    params_in_scene
** Description:
**    Parse params
**    Call put_in_scene
**    Free params
** Params:
**    char ***pl -> array of tables made with ft_split (see libft)
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
**    int i -> index in which perform operations
** Return:
**    bool -> return whether allocation was successful or not
**       [false] :: some error occurred during allocation
**       [true] :: everything is alright
*/

static bool	params_in_scene(char ***pl, t_scene *scene, int i)
{
	char **params[3];

	ft_bzero(&params, 3 * sizeof(char**));
	if (!(params[0] = ft_split(pl[i][1], ',')) || \
		!(params[1] = ft_split(pl[i][2], ',')) || \
		!(params[2] = ft_split(pl[i][3], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		ft_free_split(&(params[2]));
		return (false);
	}
	put_in_scene(pl, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	ft_free_split(&(params[2]));
	return (true);
}

/*
** Function name:
**    process_pl
** Description:
**    If char ***pl is NULL, it just returns NO_ERROR
**    Process each plane (pl) arguments and parameters
**    Allocate each object correctly and set its flag
** Params:
**    char ***pl -> array of tables (made with ft_split - more info in libft)
**                  each index of the first array (pl[index1]) is a line
**                  (i.e. a different plane) of the file. At the
**                  second index (pl[index1][index2]) is a word (string) of
**                  the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error		process_pl(char ***pl, t_scene *scene)
{
	int		i;

	if (!pl)
		return (NO_ERROR);
	if (!allocate_in_scene(pl, scene))
		return (NO_MEMORY);
	i = 0;
	while (pl[i])
		if (!params_in_scene(pl, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
