/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 03:43:18 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/19 04:15:02 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*
** "constructors" of the class t_vec3
** vec3(...)		: receives parameters as double and return object
** vec3_int(...)	: receives parameters as int and return object
*/

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.r = (int)round(x);
	v.g = (int)round(y);
	v.b = (int)round(z);
	return (v);
}

t_vec3	vec3_int(int r, int g, int b)
{
	t_vec3	v;

	v.r = r;
	v.g = g;
	v.b = b;
	v.x = (double)r;
	v.y = (double)g;
	v.z = (double)b;
	return (v);
}
