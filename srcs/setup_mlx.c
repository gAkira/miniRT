/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:34:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/06 23:55:47 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	delete_mlx_imgs(t_mlx *server)
{
	int	i;

	i = 0;
	while (server->imgs && server->imgs[i])
	{
		mlx_destroy_image(server->mlx, server->imgs[i]->id);
		free(server->imgs[i]);
		i++;
	}
	free(server->imgs);
}

int			close_mlx(t_mlx *server)
{
	delete_mlx_imgs(server);
	mlx_destroy_window(server->mlx, server->win.id);
	error_handler(EXIT_0, server->scene->args, server->scene);
	return (0);
}

static int	close_key_win(int keycode, t_mlx *server)
{
	if (keycode == 0xFF1B)
		close_mlx(server);
	return (0);
}

static bool	create_images(t_scene *scene, t_mlx *server)
{
	int		i;
	t_img	*img;

	i = 0;
	while (scene->c && scene->c[i])
		i++;
	if (i && !(server->imgs = (t_img**)ft_calloc(i + 1, sizeof(t_img*))))
		return (false);
	i = 0;
	while (scene->c && scene->c[i])
	{
		if (!(img = (t_img*)malloc(sizeof(t_img))))
			return (false);
		img->id = mlx_new_image(server->mlx, server->win.x, \
									server->win.y);
		img->addr = mlx_get_data_addr(img->id, &(img->bpp), &(img->line_len), \
									&(img->endian));
		server->imgs[i] = img;
		scene->c[i]->img = img;
		i++;
	}
	return (true);
}

t_error		setup_mlx(t_scene *scene, t_mlx *server)
{
	ft_bzero(server, sizeof(t_mlx));
	server->win.x = scene->res.x;
	server->win.y = scene->res.y;
	server->scene = scene;
	if (!(server->mlx = mlx_init()))
		return (CANT_SETUP_MLX);
	if (!(server->win.id = mlx_new_window(server->mlx, (int)server->win.x, \
										(int)server->win.y, scene->filename)))
		return (CANT_SETUP_MLX);
	if (!create_images(scene, server))
		close_mlx(server);
	mlx_key_hook(server->win.id, close_key_win, server);
	mlx_hook(server->win.id, 33, 1L << 17, close_mlx, server);
	return (NO_ERROR);
}
