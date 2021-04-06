/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:34:59 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 20:51:24 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	color_at(t_scene *scene, t_ray ray)
{
	t_intersect	**intersections;
	t_intersect	*hit_obj;
	t_comps		comps;
	t_tuple		color;

	intersections = intersect_scene(scene, ray);
	hit_obj = hit(intersections);
	if (!hit_obj)
		color = mx_vector(0, 0, 0);
	else
	{
		comps = prepare_comps(hit_obj, ray);
		color = shade_hit(scene, comps);
	}
	return (color);
}
