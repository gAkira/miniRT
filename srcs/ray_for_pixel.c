/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:53:32 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/09 00:10:48 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray	calc_ray(t_c *c, double world_x, double world_y)
{
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	pixel = mx_transform(c->inv_transform, mx_point(world_x, world_y, -1));
	origin = mx_transform(c->inv_transform, mx_point(0, 0, 0));
	direction = mx_unit(mx_sub(pixel, origin));
	return (ray(origin, direction));
}

t_ray			ray_for_pixel(t_c *c, size_t px, size_t py)
{
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;

	xoffset = ((double)px + 0.5) * c->pixel_size;
	yoffset = ((double)py + 0.5) * c->pixel_size;
	world_x = c->half_width - xoffset;
	world_y = c->half_height - yoffset;
	return (calc_ray(c, world_x, world_y));
}
