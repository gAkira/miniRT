/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:52:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 16:06:49 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	if (mx_equal(origin.pos[3], 0))
		origin.pos[3] = 1;
	if (mx_equal(direction.pos[3], 1))
		direction.pos[3] = 0;
	ray.coord = origin;
	ray.dir = direction;
	return (ray);
}

t_tuple	ray_pos(t_ray ray, double t)
{
	return (mx_sum(ray.coord, mx_prod(ray.dir, t)));
}
