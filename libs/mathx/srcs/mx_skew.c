/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_skew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:15:42 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 16:19:56 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_skew(t_tuple x, t_tuple y, t_tuple z)
{
	t_matrix	matrix;

	matrix = mx_identity(4);
	matrix.pos[0][1] = x.pos[1];
	matrix.pos[0][2] = x.pos[2];
	matrix.pos[1][0] = y.pos[0];
	matrix.pos[1][2] = y.pos[2];
	matrix.pos[2][0] = z.pos[0];
	matrix.pos[2][1] = z.pos[1];
	return (matrix);
}
