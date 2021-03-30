/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:26:26 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/27 02:30:45 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_multiply(t_matrix a, t_matrix b)
{
	size_t		i;
	size_t		k;
	t_matrix	matrix;

	matrix = mx_matrix(a.rows, b.cols);
	if (a.cols != b.rows)
		return (matrix);
	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			matrix.pos[i][k] = a.pos[i][0] * b.pos[0][k] + \
								a.pos[i][1] * b.pos[1][k] + \
								a.pos[i][2] * b.pos[2][k] + \
								a.pos[i][3] * b.pos[3][k];
			k++;
		}
		i++;
	}
	return (matrix);
}
