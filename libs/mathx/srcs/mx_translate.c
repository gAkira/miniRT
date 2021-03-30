/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:20:32 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:23:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_translate(double x, double y, double z)
{
	t_matrix	matrix;

	matrix = mx_identity(4);
	matrix.pos[0][3] = x;
	matrix.pos[1][3] = y;
	matrix.pos[2][3] = z;
	return (matrix);
}
