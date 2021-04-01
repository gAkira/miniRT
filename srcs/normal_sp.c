/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:56:01 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 20:03:06 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_sp(t_sp *sp, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;

	if (!sp)
		return (mx_vector(0, 0, 0));
	object_point = mx_transform(sp->inv_transform, world_point);
	object_normal = mx_sub(object_point, mx_point(0, 0, 0));
	world_normal = mx_transform(mx_transpose(sp->inv_transform), object_normal);
	world_normal.pos[3] = 0;
	return (mx_unit(world_normal));
}
