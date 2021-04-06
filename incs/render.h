/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:41:59 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 17:22:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mask.h"

typedef struct	s_canvas
{
	size_t		x;
	size_t		y;
	int			**pos;
}				t_canvas;

typedef struct	s_ray
{
	t_tuple		coord;
	t_tuple		dir;
}				t_ray;

typedef struct	s_intersect
{
	t_mask		mask;

	void		*obj;
	double		t;
}				t_intersect;

typedef struct	s_comps
{
	t_mask		mask;
	void		*obj;
	double		t;

	t_tuple		point;
	t_tuple		eye;
	t_tuple		light;
	t_tuple		normal;
	t_tuple		reflect;
	double		inside;
}				t_comps;

#endif
