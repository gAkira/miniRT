/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:38:42 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/02 19:53:40 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_spec(t_tuple *spec, t_material mat, t_l *l, t_lightvec lv)
{
	double	reflect_dot_eye;
	double	factor;

	reflect_dot_eye = mx_dot(lv.reflect, lv.eye);
	if (reflect_dot_eye < 0.0 || mx_equal(reflect_doy_eye, 0.0))
		*spec = mx_vector(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, mat.shininess);
		*spec = mx_prod(mx_prod(l->color, mat.specular), factor);
	}
}

t_tuple		lighting(t_material mat, t_l *l, t_lightvec lvec)
{
	double	light_dot_normal;
	t_tuple	effective_color;
	t_tuple	ambient;
	t_tuple	diffuse;
	t_tuple	specular;

	effective_color = mx_prod(mat.color, l->color);
	lvec.light = mx_unit(mx_sub(l->coord, lvec.point));
	ambient = mx_prod(effective_color, mat.ambient);
	light_dot_normal = mx_dot(lvec.light, lvec.normal);
	if (light_dot_normal < 0.0 && !mx_equal(light_dot_normal))
	{
		diffuse = mx_vector(0, 0, 0);
		specular = mx_vector(0, 0, 0);
	}
	else
	{
		diffuse = mx_prod(mx_prod(effective_color, mat.diffuse), \
															light_dot_normal);
		lvec.reflect = reflect(mx_negate(lvec.light), lvec.normal);
		set_spec(&specular, mat, l, lvec);
	}
	return (mx_sum(mx_sum(ambient, diffuse), specular));
}
