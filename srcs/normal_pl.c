/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:16:07 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/11 03:23:12 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_pl(t_pl *pl, t_tuple world_point)
{
	t_tuple	object_normal;
	t_tuple	world_normal;

	if (!pl)
		return (mx_vector(0, 0, 0));
	(void)world_point;
	object_normal = mx_vector(0, 1, 0);
	world_normal = mx_transform(mx_transpose(pl->inv_transform), object_normal);
	world_normal.pos[3] = 0;
	return (mx_unit(world_normal));
}
