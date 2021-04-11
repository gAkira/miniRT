/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:55:02 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/10 15:49:39 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_pl(t_intersect ***list, t_pl *pl, t_ray ray)
{
	double	t;

	ray = ray_transform(pl->inv_transform, ray);
	if (mx_equal(ray.dir.pos[1], 0))
		return ;
	t = -ray.coord.pos[1] / ray.dir.pos[1];
	intersections(list, intersection(pl, t, PL_MASK));
}

void	get_intersects_pl(t_intersect ***list, t_pl **pl, t_ray ray)
{
	int	i;

	i = 0;
	while (pl && pl[i])
	{
		intersect_pl(list, pl[i], ray);
		i++;
	}
}
