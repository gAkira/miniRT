/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_equalm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:43:37 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:14:00 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

bool	mx_equalm(t_matrix a, t_matrix b)
{
	size_t	i;
	size_t	k;

	if (a.rows != b.rows || a.cols != b.cols)
		return (false);
	i = 0;
	while (i < a.rows)
	{
		k = 0;
		while (k < a.cols)
		{
			if (!mx_equal(a.pos[i][k], b.pos[i][k]))
				return (false);
			k++;
		}
		i++;
	}
	return (true);
}
