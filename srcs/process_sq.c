/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:57:54 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	allocate_in_scene(char ***sq, t_scene *scene)
{
	int	i;

	i = 0;
	while (sq[i])
		i++;
	if (!(scene->sq = (t_sq*)ft_calloc(i + 1, sizeof(t_sq))))
		return (false);
	scene->sq[i].end = true;
	allocate_flag(&(scene->allocation), SQ_MASK);
	return (true);
}

static void	put_in_scene(char ***sq, char ***params, t_scene *scene, int i)
{
	scene->sq[i].coord = vec3(ft_atof(params[0][0]), \
							ft_atof(params[0][1]), \
							ft_atof(params[0][2]));
	scene->sq[i].orient = vec3(ft_atof(params[1][0]), \
							ft_atof(params[1][1]), \
							ft_atof(params[1][2]));
	scene->sq[i].side = ft_atof(sq[i][3]);
	scene->sq[i].color = vec3_int(ft_atoi(params[2][0]), \
								ft_atoi(params[2][1]), \
								ft_atoi(params[2][2]));
}

static bool	params_in_scene(char ***sq, t_scene *scene, int i)
{
	char **params[3];

	ft_bzero(&params, 3 * sizeof(char**));
	if (!(params[0] = ft_split(sq[i][1], ',')) || \
		!(params[1] = ft_split(sq[i][2], ',')) || \
		!(params[2] = ft_split(sq[i][4], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		ft_free_split(&(params[2]));
		return (false);
	}
	put_in_scene(sq, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	ft_free_split(&(params[2]));
	return (true);
}

t_error		process_sq(char ***sq, t_scene *scene)
{
	int		i;

	if (!sq)
		return (NO_ERROR);
	if (!allocate_in_scene(sq, scene))
		return (NO_MEMORY);
	i = 0;
	while (sq[i])
		if (!params_in_scene(sq, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
