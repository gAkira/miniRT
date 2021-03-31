/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_unit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:50:05 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/26 02:50:59 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_tuple	mx_unit(t_tuple a)
{
	return (mx_div(a, mx_length(a)));
}