/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:09:00 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/11 03:23:42 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_shadowed(t_scene *scene, t_tuple point)
{
	int			i;
	bool		has_shadow;
	t_intersect	**list;
	t_intersect	*h;
	t_ray		r;

	i = 0;
	has_shadow = true;
	while (has_shadow && scene && scene->l && scene->l[i])
	{
		r = ray(point, mx_unit(mx_sub(scene->l[i]->coord, point)));
		list = intersect_scene(scene, r);
		h = hit(list);
		if (h && h->t < mx_length(mx_sub(scene->l[i]->coord, point)))
			has_shadow = false;
		free_intersections(list);
		i++;
	}
	return (has_shadow);
}
