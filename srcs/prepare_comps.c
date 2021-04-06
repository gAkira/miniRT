/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_comps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:20:54 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 20:58:44 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comps	prepare_comps(t_intersect *intersect, t_ray ray)
{
	t_comps	comps;
	double	normal_dot_eye;

	comps.mask = intersect->mask;
	comps.obj = intersect->obj;
	comps.t = intersect->t;
	comps.point = ray_pos(ray, comps.t);
	comps.eye = mx_negate(ray.dir);
	comps.normal = normal_at(comps.obj, comps.point, comps.mask);
	normal_dot_eye = mx_dot(comps.normal, comps.eye);
	if (normal_dot_eye < 0.0 && !mx_equal(normal_dot_eye, 0))
	{
		comps.inside = true;
		comps.normal = mx_negate(comps.normal);
	}
	else
		comps.inside = false;
	return (comps);
}
