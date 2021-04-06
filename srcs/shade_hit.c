/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:59:31 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/05 22:23:34 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	shade_hit(t_scene *scene, t_comps comps)
{
	int			i;
	t_tuple		color;
	t_material	mat;

	i = 0;
	color = mx_vector(0, 0, 0);
	while (scene && scene->l && scene->l[i])
	{
		if (comps.mask == SP_MASK)
			mat = ((t_sp*)(comps.obj))->mat;
		else if (comps.mask == PL_MASK)
			mat = ((t_pl*)(comps.obj))->mat;
		else if (comps.mask == SQ_MASK)
			mat = ((t_sq*)(comps.obj))->mat;
		else if (comps.mask == CY_MASK)
			mat = ((t_cy*)(comps.obj))->mat;
		else if (comps.mask == TR_MASK)
			mat = ((t_tr*)(comps.obj))->mat;
		else
			mat = material();
		color = mx_sum(color, lighting(mat, scene->l[i], comps));
		i++;
	}
	return (color);
}
