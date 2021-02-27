/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 04:28:47 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/19 20:06:11 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*
** some util operations with vectors (3-dimensional):
** v3_length(...)		: length of the vector
** v3_make_unit_vec(...): transform a t_vec3 passed (by reference) into a
**															unit vector
** v3_unit_vec(...)		: return the unit version of the vector passed
** v3_unit2color(...)	: transform unit vector into color range
*/

double	v3_length(t_vec3 v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

void	v3_make_unit_vec(t_vec3 *v)
{
	double	len;

	len = v3_length(*v);
	*v = v3_prod(1.0 / len, *v);
}

t_vec3	v3_unit_vec(t_vec3 v)
{
	double	len;

	len = v3_length(v);
	return (v3_prod(1.0 / len, v));
}

t_vec3	v3_unit2color(t_vec3 v)
{
	double	x;
	double	y;
	double	z;

	x = (0.5 * (v.x + 1)) * (double)0xFF;
	y = (0.5 * (v.y + 1)) * (double)0xFF;
	z = (0.5 * (v.z + 1)) * (double)0xFF;
	return (vec3(x, y, z));
}
