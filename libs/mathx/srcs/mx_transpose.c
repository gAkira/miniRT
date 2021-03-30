/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_transpose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:46:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/27 02:53:41 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_transpose(t_matrix a)
{
	size_t		i;
	size_t		k;
	t_matrix	matrix;

	matrix = mx_matrix(a.cols, a.rows);
	i = 0;
	while (i < matrix.rows)
	{
		k = 0;
		while (k < matrix.cols)
		{
			matrix.pos[i][k] = a.pos[k][i];
			k++;
		}
		i++;
	}
	return (matrix);
}
