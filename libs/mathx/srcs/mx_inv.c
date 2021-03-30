/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 03:40:16 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:03:48 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_inv(t_matrix a)
{
	size_t		i;
	size_t		k;
	t_matrix	matrix;
	double		det_a;

	det_a = mx_det(a);
	matrix = mx_matrix(a.rows, a.cols);
	if (mx_equal(det_a, 0.0))
		return (matrix);
	i = 0;
	while (i < a.rows)
	{
		k = 0;
		while (k < a.cols)
		{
			matrix.pos[k][i] = mx_cofactor(a, i, k) / det_a;
			k++;
		}
		i++;
	}
	return (matrix);
}
