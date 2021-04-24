/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:24:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/25 00:16:19 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_xrotate(double rad)
{
	t_matrix	matrix;

	matrix = mx_identity(4);
	matrix.pos[1][1] = cos(rad);
	matrix.pos[1][2] = -sin(rad);
	matrix.pos[2][1] = sin(rad);
	matrix.pos[2][2] = cos(rad);
	return (matrix);
}

t_matrix	mx_yrotate(double rad)
{
	t_matrix	matrix;

	matrix = mx_identity(4);
	matrix.pos[0][0] = cos(rad);
	matrix.pos[0][2] = sin(rad);
	matrix.pos[2][0] = -sin(rad);
	matrix.pos[2][2] = cos(rad);
	return (matrix);
}

t_matrix	mx_zrotate(double rad)
{
	t_matrix	matrix;

	matrix = mx_identity(4);
	matrix.pos[0][0] = cos(rad);
	matrix.pos[0][1] = -sin(rad);
	matrix.pos[1][0] = sin(rad);
	matrix.pos[1][1] = cos(rad);
	return (matrix);
}
