/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:31:59 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/27 02:38:59 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_tuple	mx_transform(t_matrix m, t_tuple t)
{
	size_t	i;
	t_tuple	tuple;

	tuple = mx_tuple(0, 0, 0, 0);
	i = 0;
	while (i < 4)
	{
		tuple.pos[i] = m.pos[i][0] * t.pos[0] + \
						m.pos[i][1] * t.pos[1] + \
						m.pos[i][2] * t.pos[2] + \
						m.pos[i][3] * t.pos[3];
		i++;
	}
	return (tuple);
}
