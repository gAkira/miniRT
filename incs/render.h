/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:41:59 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 15:50:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

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

#endif
