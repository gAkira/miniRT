/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_identity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:42:26 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/27 02:45:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_identity(size_t mn)
{
	size_t		i;
	t_matrix	matrix;

	matrix = mx_matrix(mn, mn);
	i = 0;
	while (i < mn)
	{
		matrix.pos[i][i] = 1;
		i++;
	}
	return (matrix);
}
