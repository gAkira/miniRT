/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_det.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:12:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 03:34:05 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"
#include <stdio.h>

double	mx_det(t_matrix a)
{
	size_t	k;
	double	det;

	det = 0.0;
	if (a.rows != a.cols)
		return (det);
	if (a.rows == 2)
		return (a.pos[0][0] * a.pos[1][1] - a.pos[0][1] * a.pos[1][0]);
	k = 0;
	while (k < a.cols)
	{
		det += a.pos[0][k] * mx_cofactor(a, 0, k);
		k++;
	}
	return (det);
}
