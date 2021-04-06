/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:56:50 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 20:39:48 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect **intersect_scene(t_scene *scene, t_ray ray)
{
	t_intersect	**intersections;

	intersections = NULL;
	get_intersects_sp(&intersections, scene->sp, ray);
	/*
	get_intersects_pl(&intersections, scene->pl, ray);
	get_intersects_sq(&intersections, scene->sq, ray);
	get_intersects_cy(&intersections, scene->cy, ray);
	get_intersects_tr(&intersections, scene->tr, ray);
	*/
	return (intersections);
}