/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:26:16 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/10 00:20:50 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normal_at(void *obj, t_tuple world_point, t_mask mask)
{
	if (mask == SP_MASK)
		return (normal_sp((t_sp*)obj, world_point));
	else if (mask == PL_MASK)
		return (normal_pl((t_pl*)obj, world_point));
	/*
	else if (mask == SQ_MASK)
		return (normal_sq((t_sq*)obj, world_point));
	else if (mask == CY_MASK)
		return (normal_cy((t_cy*)obj, world_point));
	else if (mask == TR_MASK)
		return (normal_tr((t_tr*)obj, world_point));
	*/
	return (mx_vector(0, 0, 0));
}
