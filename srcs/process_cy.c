/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 19:09:41 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	scene->cy[i]->color = mx_vector(ft_atoi(params[2][0]), \
								ft_atoi(params[2][1]), \
								ft_atoi(params[2][2]));
}

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
