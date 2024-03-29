/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_prod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:36:27 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/27 02:24:08 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_tuple	mx_prod(t_tuple a, double k)
{
	return (mx_tuple(a.pos[0] * k, \
					a.pos[1] * k, \
					a.pos[2] * k, \
					a.pos[3] * k));
}
