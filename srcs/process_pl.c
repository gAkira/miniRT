/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 20:53:59 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
