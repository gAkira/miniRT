/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_submatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:04:32 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/29 20:37:42 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_submatrix(t_matrix a, size_t row, size_t col)
{
	size_t		i;
	size_t		k;
	t_matrix	submatrix;

	submatrix = mx_matrix(a.rows - 1, a.cols - 1);
	i = 0;
	while (i < a.rows)
	{
		k = 0;
		while (k < a.cols)
		{
			if (i < row && k < col)
				submatrix.pos[i][k] = a.pos[i][k];
			else if (i < row && k > col)
				submatrix.pos[i][k - 1] = a.pos[i][k];
			else if (i > row && k < col)
				submatrix.pos[i - 1][k] = a.pos[i][k];
			else if (i > row && k > col)
				submatrix.pos[i - 1][k - 1] = a.pos[i][k];
			k++;
		}
		i++;
	}
	return (submatrix);
}
