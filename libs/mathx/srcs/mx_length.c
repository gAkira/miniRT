/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 02:45:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/26 02:53:03 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mathx.h"

double	mx_length(t_tuple a)
{
	return (sqrt(pow(a.pos[0], 2) + \
				pow(a.pos[1], 2) + \
				pow(a.pos[2], 2) + \
				pow(a.pos[3], 2)));
}
