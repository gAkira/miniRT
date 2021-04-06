/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_server.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:23:36 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/06 21:44:54 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SERVER_H
# define MLX_SERVER_H

typedef struct	s_img
{
	void		*id;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_win
{
	void		*id;
	size_t		x;
	size_t		y;
}				t_win;

typedef struct s_scene t_scene;

typedef struct	s_mlx
{
	void		*mlx;
	t_win		win;

	t_img		**imgs;

	t_scene		*scene;
}				t_mlx;

#endif
