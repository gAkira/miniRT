/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:21:14 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/25 00:17:43 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHX_H
# define MATHX_H

# include <math.h>
# include <stddef.h>
# include <stdbool.h>

# define MX_EPSILON 0.00001

typedef struct s_tuple
{
	size_t		length;
	double		pos[4];
}				t_tuple;

typedef struct s_matrix
{
	size_t		rows;
	size_t		cols;
	double		pos[4][4];
}				t_matrix;

/*
** Constructors
*/

t_tuple		mx_tuple(double x, double y, double z, double w);
t_tuple		mx_point(double x, double y, double z);
t_tuple		mx_vector(double x, double y, double z);
t_matrix	mx_matrix(size_t m, size_t n);
t_matrix	mx_identity(size_t mn);

/*
** Utility methods
*/

bool		mx_equal(double a, double b);
bool		mx_equalxyz(t_tuple a, t_tuple b);
bool		mx_equalt(t_tuple a, t_tuple b);
bool		mx_equalm(t_matrix a, t_matrix b);

/*
** Tuple operations
*/

t_tuple		mx_negate(t_tuple a);
t_tuple		mx_sum(t_tuple a, t_tuple b);
t_tuple		mx_sub(t_tuple a, t_tuple b);
t_tuple		mx_prod(t_tuple a, double k);
t_tuple		mx_div(t_tuple a, double k);
double		mx_length(t_tuple a);
t_tuple		mx_unit(t_tuple a);
void		mx_to_unit(t_tuple *a);
double		mx_dot(t_tuple a, t_tuple b);
t_tuple		mx_cross(t_tuple a, t_tuple b);

/*
** Matrix operations
*/

t_matrix	mx_multiply(t_matrix a, t_matrix b);
t_tuple		mx_transform(t_matrix m, t_tuple t);
t_matrix	mx_transpose(t_matrix a);
t_matrix	mx_submatrix(t_matrix a, size_t row, size_t col);
double		mx_minor(t_matrix a, size_t row, size_t col);
double		mx_cofactor(t_matrix a, size_t row, size_t col);
double		mx_det(t_matrix a);
t_matrix	mx_inv(t_matrix a);
t_matrix	mx_translate(double x, double y, double z);
t_matrix	mx_scale(double x, double y, double z);
t_matrix	mx_xrotate(double rad);
t_matrix	mx_yrotate(double rad);
t_matrix	mx_zrotate(double rad);
t_matrix	mx_xrotated(double deg);
t_matrix	mx_yrotated(double deg);
t_matrix	mx_zrotated(double deg);
t_matrix	mx_skew(t_tuple x, t_tuple y, t_tuple z);

#endif
