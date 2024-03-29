/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:10:57 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/07 16:45:14 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "render.h"
# include "mlx_server.h"

typedef struct	s_material
{
	t_tuple		color;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;

/*
** For a better look about the attributes of these structures, see the
** miniRT's subject file
*/

typedef struct	s_res
{
	size_t		x;
	size_t		y;
}				t_res;

typedef struct	s_amb
{
	double		ratio;
	t_tuple		color;
}				t_amb;

typedef struct	s_c
{
	t_tuple		coord;
	t_tuple		dir;
	size_t		fov;

	double		half_width;
	double		half_height;
	double		pixel_size;

	t_matrix	transform;
	t_matrix	inv_transform;

	t_img		*img;
	t_canvas	*canvas;
}				t_c;

typedef struct	s_l
{
	t_tuple		coord;
	double		ratio;
	t_tuple		color;
}				t_l;

typedef struct	s_pl
{
	t_tuple		coord;
	t_tuple		dir;
	t_material	mat;
	t_matrix	transform;
	t_matrix	inv_transform;
}				t_pl;

typedef struct	s_sp
{
	t_tuple		coord;
	double		diam;
	t_material	mat;
	t_matrix	transform;
	t_matrix	inv_transform;
}				t_sp;

typedef struct	s_sq
{
	t_tuple		coord;
	t_tuple		dir;
	double		side;
	t_material	mat;
	t_matrix	transform;
	t_matrix	inv_transform;
}				t_sq;

typedef struct	s_cy
{
	t_tuple		coord;
	t_tuple		dir;
	double		diam;
	double		height;
	t_material	mat;
	t_matrix	transform;
	t_matrix	inv_transform;
}				t_cy;

typedef struct	s_tr
{
	t_tuple		coord[3];
	t_material	mat;
	t_matrix	transform;
	t_matrix	inv_transform;
}				t_tr;

typedef struct	s_scene
{
	size_t		allocation;

	char		*filename;

	t_res		res;
	t_amb		amb;
	t_c			**c;
	t_l			**l;
	t_pl		**pl;
	t_sp		**sp;
	t_sq		**sq;
	t_cy		**cy;
	t_tr		**tr;

	t_args		*args;
}				t_scene;

#endif
