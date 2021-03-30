/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:25:33 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:27:18 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_scale(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = mx_matrix(4, 4);
	matrix.pos[0][0] = x;
	matrix.pos[1][1] = y;
	matrix.pos[2][2] = z;
	matrix.pos[3][3] = 1.0;
	return (matrix);
}
