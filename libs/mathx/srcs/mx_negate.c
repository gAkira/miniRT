/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_negate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:17:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/26 04:13:04 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_tuple	mx_negate(t_tuple a)
{
	return (mx_tuple(-(a.pos[0]), \
					-(a.pos[1]), \
					-(a.pos[2]), \
					-(a.pos[3])));
}