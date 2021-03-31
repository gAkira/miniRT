/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hadamard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:26:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 03:32:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	hadamard(t_tuple color1, t_tuple color2)
{
	return (mx_vector(color1.pos[0] * color2.pos[0], \
						color1.pos[1] * color2.pos[1], \
						color1.pos[2] * color2.pos[2]));
}
