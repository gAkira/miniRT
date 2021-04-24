/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_tuple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:40:49 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/25 00:16:55 by galves-d         ###   ########.fr       */
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

t_tuple	mx_tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	mx_bzero(&tuple, sizeof(t_tuple));
	tuple.length = 4;
	tuple.pos[0] = x;
	tuple.pos[1] = y;
	tuple.pos[2] = z;
	tuple.pos[3] = w;
	return (tuple);
}
