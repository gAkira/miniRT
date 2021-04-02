/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:19:54 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/02 21:05:34 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_sp(t_intersect ***list, t_sp *sp, t_ray ray)
{
	double	abc[3];
	double	t[2];
	double	discriminant;
	t_tuple	sp_to_ray;

	ray = ray_transform(sp->inv_transform, ray);
	sp_to_ray = mx_sub(ray.coord, mx_point(0, 0, 0));
	abc[0] = mx_dot(ray.dir, ray.dir);
	abc[1] = 2.0 * mx_dot(ray.dir, sp_to_ray);
	abc[2] = mx_dot(sp_to_ray, sp_to_ray) - 1.0;
	discriminant = pow(abc[1], 2) - 4.0 * abc[0] * abc[2];
	if (mx_equal(discriminant, 0.0))
	{
		t[0] = -abc[1] / (2.0 * abc[0]);
		t[1] = t[0];
		intersections(list, intersection(sp, t[0], SP_MASK));
		intersections(list, intersection(sp, t[1], SP_MASK));
	}
	else if (discriminant > 0.0)
	{
		t[0] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
		t[1] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
		intersections(list, intersection(sp, t[0], SP_MASK));
		intersections(list, intersection(sp, t[1], SP_MASK));
	}
}

void	get_intersects_sp(t_intersect ***list, t_sp **sp, t_ray ray)
{
	int	i;

	i = 0;
	while (sp && sp[i])
	{
		intersect_sp(list, sp[i], ray);
		i++;
	}
}
