/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:52:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 19:13:29 by galves-d         ###   ########.fr       */
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

t_tuple	ray_pos(t_ray r, double t)
{
	return (mx_sum(r.coord, mx_prod(r.dir, t)));
}

t_ray	ray_transform(t_matrix m, t_ray r)
{
	t_tuple	origin;
	t_tuple	direction;

	origin = mx_transform(m, r.coord);
	direction = mx_transform(m, r.dir);
	return (ray(origin, direction));
}
