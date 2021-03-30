/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:56:59 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:13:07 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mathx.h"

void	print_tuple(char *str, t_tuple t);
void	test_constructors();
void	test_equals();
void	test_operations();
void	test_determinant();
void	test_inverse();

int		main(void)
{
	test_constructors();
	test_equals();
	test_operations();
	test_determinant();
	test_inverse();
}





void	print_tuple(char *str, t_tuple t)
{
	printf("%s:\n\tx: %.3f, y: %.3f, z: %.3f, w: %.3f\n\n", \
			(str ? str : (((bool)t.pos[3]) ? "point" : "vector")), \
			t.pos[0], t.pos[1], t.pos[2], t.pos[3]);
}

void	print_matrix(char *str, t_matrix m)
{
	printf("%s:\n", (str ? str : "matrix"));
	for (int i = 0 ; i < m.rows ; i++)
	{
		printf("\t|");
		for (int k = 0 ; k < m.cols ; k++)
			printf(" %8.5f |", m.pos[i][k]);
		printf("\n");
	}
}

void	test_constructors()
{
	t_tuple	tuple;
	t_tuple	point;
	t_tuple	vector;
	double	t[4] = {1, 2, 3, 10};
	double	p[3] = {3, 2, 1};
	double	v[3] = {5, 6, 7};

	tuple = mx_tuple(t[0], t[1], t[2], t[3]);
	point = mx_point(p[0], p[1], p[2]);
	vector = mx_vector(v[0], v[1], v[2]);

	printf("###############################################################\n");
	printf(">>> Testing Constructors\n");
	printf("###############################################################\n");
	printf("USE: mx_tuple(%.2f, %.2f, %.2f, %.2f);\n", t[0], t[1], t[2], t[3]);
	print_tuple("tuple", tuple);
	printf("USE: mx_point(%.2f, %.2f, %.2f);\n", p[0], p[1], p[2]);
	print_tuple("point", point);
	printf("USE: mx_vector(%.2f, %.2f, %.2f);\n", v[0], v[1], v[2]);
	print_tuple("vector", vector);
}

void	test_equals()
{
	/*
	t_tuple	tpl1;
	t_tuple	tpl1;
	t_tuple	pnt;
	t_tuple	vct;
	double	t1[4] = {1, 2, 3, 10};
	double	t2[4] = {1, 2, 3, 10};
	double	p[3] = {3, 2, 1};
	double	v[3] = {5, 6, 7};
	*/
	double	n_eq[2] = {4.0 * 2.0, 16.0 / 2.0};
	double	n_neq[2] = {1.0, 1 + MX_EPSILON};

	/*
	tpl1 = mx_tuple(t1[0], t1[1], t1[2], t1[3]);
	tpl2 = mx_tuple(t2[0], t2[1], t2[2], t2[3]);
	pnt = mx_point(p[0], p[1], p[2]);
	vct = mx_vector(v[0], v[1], v[2]);
	*/

	printf("###############################################################\n");
	printf(">>> Testing Equals\n");
	printf("###############################################################\n");
	printf("USE: mx_equal(%.9f, %.9f);\n", n_eq[0], n_eq[1]);
	printf("Result\n\t%s\n\n", (mx_equal(n_eq[0], n_eq[1]) ? "true" : "false"));
	printf("USE: mx_equal(%.9f, %.9f);\n", n_neq[0], n_neq[1]);
	printf("Result\n\t%s\n\n", (mx_equal(n_neq[0], n_neq[1]) ? "true" : "false"));
}

void	test_operations()
{
	t_tuple	tpl1;
	t_tuple	tpl2;
	t_tuple	tpl3;
	t_tuple	pnt1;
	t_tuple	pnt2;
	t_tuple	vct1;
	t_tuple	vct2;
	double	t1[4] = {3, -2, 5, 1};
	double	t2[4] = {-2, 3, 1, 0};
	double	t3[4] = {1, -2, 3, -4};
	double	p1[3] = {3, 2, 1};
	double	p2[3] = {5, 6, 7};
	double	v1[3] = {3, 2, 1};
	double	v2[3] = {5, 6, 7};
	double	sp1 = 3.5;
	double	sp2 = 0.5;
	double	sd1 = 2;

	tpl1 = mx_tuple(t1[0], t1[1], t1[2], t1[3]);
	tpl2 = mx_tuple(t2[0], t2[1], t2[2], t2[3]);
	tpl3 = mx_tuple(t3[0], t3[1], t3[2], t3[3]);

	pnt1 = mx_point(p1[0], p1[1], p1[2]);
	pnt2 = mx_point(p2[0], p2[1], p2[2]);
	
	vct1 = mx_vector(v1[0], v1[1], v1[2]);
	vct2 = mx_vector(v2[0], v2[1], v2[2]);
	
	printf("###############################################################\n");
	printf(">>> Testing Operations\n");
	printf("###############################################################\n");
	printf("USE: mx_sum(tuple(%.2f, %.2f, %.2f, %.2f), tuple(%.2f, %.2f, %.2f, %.2f));\n", \
						t1[0], t1[1], t1[2], t1[3], \
						t2[0], t2[1], t2[2], t2[3]);
	print_tuple(NULL, mx_sum(tpl1, tpl2));
	printf("USE: mx_sub(point(%.2f, %.2f, %.2f), point(%.2f, %.2f, %.2f));\n", \
						p1[0], p1[1], p1[2], \
						p2[0], p2[1], p2[2]);
	print_tuple(NULL, mx_sub(pnt1, pnt2));
	printf("USE: mx_sub(point(%.2f, %.2f, %.2f), vector(%.2f, %.2f, %.2f));\n", \
						p1[0], p1[1], p1[2], \
						v2[0], v2[1], v2[2]);
	print_tuple(NULL, mx_sub(pnt1, vct2));
	printf("USE: mx_sub(vector(%.2f, %.2f, %.2f), vector(%.2f, %.2f, %.2f));\n", \
						v1[0], v1[1], v1[2], \
						v2[0], v2[1], v2[2]);
	print_tuple(NULL, mx_sub(vct1, vct2));
	printf("USE: mx_negate(tuple(%.2f, %.2f, %.2f, %.2f));\n", \
						t3[0], t3[1], t3[2], t3[3]);
	print_tuple("tuple", mx_negate(tpl3));
	printf("USE: mx_prod(tuple(%.2f, %.2f, %.2f, %.2f), %.2f);\n", \
						t3[0], t3[1], t3[2], t3[3], \
						sp1);
	print_tuple("tuple", mx_prod(tpl3, sp1));
	printf("USE: mx_prod(tuple(%.2f, %.2f, %.2f, %.2f), %.2f);\n", \
						t3[0], t3[1], t3[2], t3[3], \
						sp2);
	print_tuple("tuple", mx_prod(tpl3, sp2));
	printf("USE: mx_div(tuple(%.2f, %.2f, %.2f, %.2f), %.2f);\n", \
						t3[0], t3[1], t3[2], t3[3], \
						sd1);
	print_tuple("tuple", mx_div(tpl3, sd1));
}

void	test_determinant()
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;
	int			mx1[3][3] =	{ \
								{1, 2, 6}, \
								{-5, 8, -4}, \
								{2, 6, 4} \
							};
	int			mx2[4][4] =	{ \
								{-2, -8, 3, 5}, \
								{-3, 1, 7, 3}, \
								{1, 2, -9, 6}, \
								{-6, 7, 7, -9} \
							};
	int			mx3[4][4] =	{ \
								{6, 4, 4, 4}, \
								{5, 5, 7, 6}, \
								{4, -9, 3, -7}, \
								{9, 1, 7, -6} \
							};

	m1 = mx_matrix(3, 3);
	for (int i = 0; i < 3; i++)
		for (int k = 0; k < 3; k++)
			m1.pos[i][k] = (double)mx1[i][k];
	m2 = mx_matrix(4, 4);
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			m2.pos[i][k] = (double)mx2[i][k];
	m3 = mx_matrix(4, 4);
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			m3.pos[i][k] = (double)mx3[i][k];

	printf("###############################################################\n");
	printf(">>> Testing Determinant\n");
	printf("###############################################################\n");
	printf("USE: mx_det(m1) = %f\n", mx_det(m1));
	printf("USE: mx_det(m2) = %f\n", mx_det(m2));
	printf("USE: mx_det(m3) = %f\n", mx_det(m3));
}

void	test_inverse()
{
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m3;
	int			mx1[4][4] =	{ \
								{-5, 2, 6, -8}, \
								{1, -5, 1, 8}, \
								{7, 7, -6, -7}, \
								{1, -3, 7, 4} \
							};
	int			mx2[4][4] =	{ \
								{8, -5, 9, 2}, \
								{7, 5, 6, 1}, \
								{-6, 0, 9, 6}, \
								{-3, 0, -9, -4} \
							};
	int			mx3[4][4] =	{ \
								{9, 3, 0, 9}, \
								{-5, -2, -6, -3}, \
								{-4, 9, 6, 4}, \
								{-7, 6, 6, 2} \
							};

	m1 = mx_matrix(4, 4);
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			m1.pos[i][k] = (double)mx1[i][k];
	m2 = mx_matrix(4, 4);
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			m2.pos[i][k] = (double)mx2[i][k];
	m3 = mx_matrix(4, 4);
	for (int i = 0; i < 4; i++)
		for (int k = 0; k < 4; k++)
			m3.pos[i][k] = (double)mx3[i][k];

	printf("###############################################################\n");
	printf(">>> Testing Inverse\n");
	printf("###############################################################\n");
	printf("USE: mx_inv(m1)\n");
	print_matrix(NULL, mx_inv(m1));
	printf("USE: mx_inv(m2)\n");
	print_matrix(NULL, mx_inv(m2));
	printf("USE: mx_inv(m3)\n");
	print_matrix(NULL, mx_inv(m3));
	print_matrix(NULL, mx_multiply(m3, mx_inv(m3)));
	printf("%s\n", (mx_equalm(mx_identity(4), mx_multiply(m3, mx_inv(m3)))) ? \
								"true" : "false");
}
