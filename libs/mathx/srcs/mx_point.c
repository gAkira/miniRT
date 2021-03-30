/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:54:56 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/26 01:56:41 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_tuple	mx_point(double x, double y, double z)
{
	return (mx_tuple(x, y, z, 1.0));
}
