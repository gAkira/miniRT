/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_basic_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 03:55:09 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/19 04:26:24 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*
** basic vector (3-dimensional) operations, such as:
** v3_sum(...)		: vector sum
** v3_sub(...)		: vector subtraction
** v3_prod(...)		: vector product by scalar (scaling)
** v3_cross(...)	: vector cross product (outer product)
** v3_dot(...)		: vector dot product (inner product)
*/

t_vec3	v3_sum(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	v3_sub(t_vec3 a, t_vec3 b)
{
	return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vec3	v3_prod(double k, t_vec3 v)
{
	return (vec3(k * v.x, k * v.y, k * v.z));
}

t_vec3	v3_cross(t_vec3 a, t_vec3 b)
{
	double	x;
	double	y;
	double	z;

	x = (a.y * b.z) - (a.z * b.y);
	y = -((a.x * b.z) - (a.z * b.x));
	z = (a.x * b.y) - (a.y * b.x);
	return (vec3(x, y, z));
}

double	v3_dot(t_vec3 a, t_vec3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
