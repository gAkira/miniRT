/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:09:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:17:06 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_dealloc(void *addr, size_t *alloc, t_mask mask)
{
	free(addr);
	deallocate_flag(alloc, mask);
}

void		free_scene(t_scene *scene)
{
	if (is_allocated_flag(scene->allocation, C_MASK))
		free_dealloc(scene->c, &(scene->allocation), C_MASK);
	if (is_allocated_flag(scene->allocation, L_MASK))
		free_dealloc(scene->l, &(scene->allocation), L_MASK);
	if (is_allocated_flag(scene->allocation, PL_MASK))
		free_dealloc(scene->pl, &(scene->allocation), PL_MASK);
	if (is_allocated_flag(scene->allocation, SP_MASK))
		free_dealloc(scene->sp, &(scene->allocation), SP_MASK);
	if (is_allocated_flag(scene->allocation, SQ_MASK))
		free_dealloc(scene->sq, &(scene->allocation), SQ_MASK);
	if (is_allocated_flag(scene->allocation, CY_MASK))
		free_dealloc(scene->cy, &(scene->allocation), CY_MASK);
	if (is_allocated_flag(scene->allocation, TR_MASK))
		free_dealloc(scene->tr, &(scene->allocation), TR_MASK);
}
