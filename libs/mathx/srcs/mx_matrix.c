/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:38:40 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/25 00:15:45 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

static void	mx_bzero(void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		((char *)addr)[i++] = '\0';
}

t_matrix	mx_matrix(size_t m, size_t n)
{
	t_matrix	matrix;

	mx_bzero(&matrix, sizeof(t_matrix));
	matrix.rows = m;
	matrix.cols = n;
	return (matrix);
}
