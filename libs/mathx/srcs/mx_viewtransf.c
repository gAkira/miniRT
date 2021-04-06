/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_viewtransf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:47:35 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 23:59:31 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_viewtransf(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	orientation;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	forward = mx_unit(mx_sub(to, from));
	left = mx_cross(forward, mx_unit(up));
	true_up = mx_cross(left, forward);
	orientation = mx_identity(4);
	orientation.pos[0][0] = left.pos[0];
	orientation.pos[0][1] = left.pos[1];
	orientation.pos[0][2] = left.pos[2];
	orientation.pos[1][0] = true_up.pos[0];
	orientation.pos[1][1] = true_up.pos[1];
	orientation.pos[1][2] = true_up.pos[2];
	orientation.pos[2][0] = -forward.pos[0];
	orientation.pos[2][1] = -forward.pos[1];
	orientation.pos[2][2] = -forward.pos[2];
	return (mx_multiply(orientation, \
				mx_translate(-from.pos[0], -from.pos[1], -from.pos[2])));
}
