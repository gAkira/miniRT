/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_objs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:25:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 00:03:22 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error	process_objs(t_args *args, t_scene *scene)
{
	t_error error;

	error = NO_ERROR;
	ft_bzero(scene, sizeof(t_scene));
	if((error = process_res(args->res, scene)) || \
		(error = process_amb(args->amb, scene))  || \
		(error = process_c(args->c, scene))) { /*|| \
		(error = process_l(args->l, scene)) || \
		(error = process_pl(args->pl, scene)) || \
		(error = process_sp(args->sp, scene)) || \
		(error = process_sq(args->sq, scene)) || \
		(error = process_cy(args->cy, scene)) || \
		(error = process_tr(args->tr, scene)))*/
		return (error);
	}
	return (error);
}
