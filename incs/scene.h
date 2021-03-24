/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:10:57 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:55:08 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/*
** Image information
*/

typedef struct	s_img
{
	void		*id;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

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
	t_vec3		color;
}				t_amb;

typedef struct	s_c
{
	t_vec3		coord;
	t_vec3		orient;
	size_t		fov;
	t_img		*img;

	bool		end;
}				t_c;

typedef struct	s_l
{
	t_vec3		coord;
	double		ratio;
	t_vec3		color;

	bool		end;
}				t_l;

typedef struct	s_pl
{
	t_vec3		coord;
	t_vec3		orient;
	t_vec3		color;

	bool		end;
}				t_pl;

typedef struct	s_sp
{
	t_vec3		coord;
	double		diam;
	t_vec3		color;

	bool		end;
}				t_sp;

typedef struct	s_sq
{
	t_vec3		coord;
	t_vec3		orient;
	double		side;
	t_vec3		color;

	bool		end;
}				t_sq;

typedef struct	s_cy
{
	t_vec3		coord;
	t_vec3		orient;
	double		diam;
	double		height;
	t_vec3		color;

	bool		end;
}				t_cy;

typedef struct	s_tr
{
	t_vec3		coord[3];
	t_vec3		color;

	bool		end;
}				t_tr;

typedef struct	s_scene
{
	size_t		allocation;

	t_res		res;
	t_amb		amb;
	t_c			*c;
	t_l			*l;
	t_pl		*pl;
	t_sp		*sp;
	t_sq		*sq;
	t_cy		*cy;
	t_tr		*tr;
}				t_scene;

#endif
