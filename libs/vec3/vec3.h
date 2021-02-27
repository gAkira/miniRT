/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 03:04:26 by user42            #+#    #+#             */
/*   Updated: 2021/02/19 20:08:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct	s_vec3
{
	int			r;
	int			g;
	int			b;
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_int(int r, int g, int b);
t_vec3			v3_sum(t_vec3 a, t_vec3 b);
t_vec3			v3_sub(t_vec3 a, t_vec3 b);
t_vec3			v3_prod(double k, t_vec3 v);
t_vec3			v3_cross(t_vec3 a, t_vec3 b);
double			v3_dot(t_vec3 a, t_vec3 b);
double			v3_length(t_vec3 v);
void			v3_make_unit_vec(t_vec3 *v);
t_vec3			v3_unit_vec(t_vec3 v);
t_vec3			v3_unit2color(t_vec3 v);

#endif
