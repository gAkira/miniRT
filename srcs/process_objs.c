/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:25:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 02:48:25 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

/*
** Function name:
**    process_objs
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

t_error		process_objs(t_args *args, t_scene *scene)
{
	t_error error;

	error = NO_ERROR;
	ft_bzero(scene, sizeof(t_scene));
	allocate_flag(&(args->allocation), SCENE_MASK);
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
