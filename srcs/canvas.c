/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 00:26:51 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 03:40:38 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    create_canvas
** Description:
**    Create a canvas (t_canvas) instance with dimensions of [ x , y ]
** Params:
**    size_t x -> x length of the canvas
**    size_t y -> y length of the canvas
** Return:
**    t_canvas* -> address of the canvas allocated
**       [NULL] :: something went wrong
**       some address :: everything is alright
*/

t_canvas	*create_canvas(size_t x, size_t y)
{
	int			i;
	t_canvas	*canvas;

	if (!(canvas = (t_canvas*)ft_calloc(1, sizeof(t_canvas))))
		return (NULL);
	if (!(canvas->pos = (int**)malloc(y * sizeof(int*))))
		return (canvas);
	i = 0;
	while ((size_t)i < y)
	{
		if (!(canvas->pos[i] = (int*)malloc(x * sizeof(int))))
		{
			while (--i >= 0)
				free(canvas->pos[i]);
			free(canvas->pos);
			canvas->pos = NULL;
			return (canvas);
		}
		i++;
	}
	canvas->x = x;
	canvas->y = y;
	return (canvas);
}

/*
** Function name:
**    free_canvas
** Description:
**    Delete a canvas instance and its content
** Params:
**    t_canvas *canvas -> canvas to be freed
** Return:
**    ---
*/

void		free_canvas(t_canvas *canvas)
{
	size_t	i;

	if (!canvas->pos)
		return ;
	i = 0;
	while (i < canvas->y)
		free(canvas->pos[i++]);
	free(canvas->pos);
	free(canvas);
}

/*
** Function name:
**    write_canvas
** Description:
**    Write an int value to the correspondent coordinate in the canvas
**    Origin of the coordinate system is at the bottom left of the canvas
** Params:
**    t_canvas *canvas -> canvas to write
**    size_t x -> x position to write
**    size_t y -> y position to write
**    int color -> color to write
** Return:
**    ---
*/

void		write_canvas(t_canvas *canvas, size_t x, size_t y, int color)
{
	if (!canvas->pos)
		return ;
	canvas->pos[canvas->y - y][x] = color;
}

/*
** Function name:
**    read_canvas
** Description:
**    Returns the color at the canvas in position (x,y)
** Params:
**    t_canvas *canvas -> canvas to read
**    size_t x -> x position to write
**    size_t y -> y position to write
** Return:
**    int -> pixel value
**       value :: (alpha << 24 | r << 16 | g << 8 | b << 0)
*/

int			read_canvas(t_canvas *canvas, size_t x, size_t y)
{
	return (canvas->pos[y][x]);
}
