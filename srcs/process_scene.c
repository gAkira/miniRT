/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:25:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/06 17:31:28 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

/*
** [STATIC] Function name:
**    copy_filename
** Description:
**    Copy filename of the scene file (without '.rt') in args to scene struct
**    Set its flag
** Params:
**    t_args *args -> reference to a struct containing the name of the scene
**                    file
**    t_scene *scene -> reference to a scene instance to store the name without
**                      .rt extension
** Return:
**    ---
*/

static void	copy_filename(t_args *args, t_scene *scene)
{
	size_t	len;

	len = ft_strlen(args->filename);
	scene->filename = (char*)ft_calloc(len - 2, sizeof(char));
	if (scene->filename)
	{
		ft_memmove(scene->filename, args->filename, (len - 3) * sizeof(char));
		allocate_flag(&(scene->allocation), FILENAME_MASK);
	}
}

/*
** Function name:
**    process_scene
** Description:
**    Process each type of object and if some error occurr, returns it
** Params:
**    t_args *args -> reference to a struct containing all content of the
**                    scene file
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory properly
**       other values :: each function will return its correspondent error code
*/

t_error		process_scene(t_args *args, t_scene *scene)
{
	t_error error;

	error = NO_ERROR;
	ft_bzero(scene, sizeof(t_scene));
	allocate_flag(&(args->allocation), SCENE_MASK);
	scene->args = args;
	if (args->save)
		copy_filename(args, scene);
	if ((error = process_res(args->res, scene)) || \
		(error = process_amb(args->amb, scene)) || \
		(error = process_c(args->c, scene)) || \
		(error = process_l(args->l, scene)) || \
		(error = process_pl(args->pl, scene)) || \
		(error = process_sp(args->sp, scene)) || \
		(error = process_sq(args->sq, scene)) || \
		(error = process_cy(args->cy, scene)) || \
		(error = process_tr(args->tr, scene)))
		return (error);
	return (error);
}
