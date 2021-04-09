/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 23:55:02 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/10 00:21:09 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_pl(t_intersect ***list, t_pl *pl, t_ray ray)
{
	double	t[2];

	ray = ray_transform(pl->inv_transform, ray);
	if (mx_equal(ray.dir.pos[1], 0))
		return ;
	
}
