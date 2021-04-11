/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 20:56:50 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/10 15:54:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect **intersect_scene(t_scene *scene, t_ray ray)
{
	t_intersect	**list;

	list = NULL;
	get_intersects_sp(&list, scene->sp, ray);
	get_intersects_pl(&list, scene->pl, ray);
	/*
	get_intersects_sq(&list, scene->sq, ray);
	get_intersects_cy(&list, scene->cy, ray);
	get_intersects_tr(&list, scene->tr, ray);
	*/
	return (list);
}
