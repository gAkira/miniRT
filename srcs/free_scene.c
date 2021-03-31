/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:09:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 02:47:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_null(void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((char*)addr)[i] != '\0')
			return (false);
		i++;
	}
	return (true);
}

static void	free_dealloc(void *addr, size_t size, size_t *alloc, t_mask mask)
{
	size_t	i;

	i = 0;
	while (!is_null(addr + i, size))
	{
		free(*((void**)(addr + i)));
		i += size;
	}
	free(addr);
	deallocate_flag(alloc, mask);
}

static void	free_dealloc_cam(t_c **c, size_t *alloc)
{
	size_t	i;

	i = 0;
	while (c && c[i])
		free_canvas(c[i++]->canvas);
	free_dealloc(c, sizeof(t_c*), alloc, C_MASK);
}

void		free_scene(t_scene *scene)
{
	if (is_allocated_flag(scene->allocation, C_MASK))
		free_dealloc_cam(scene->c, &(scene->allocation));
	if (is_allocated_flag(scene->allocation, L_MASK))
		free_dealloc(scene->l, sizeof(t_l*), &(scene->allocation), L_MASK);
	if (is_allocated_flag(scene->allocation, PL_MASK))
		free_dealloc(scene->pl, sizeof(t_pl*), &(scene->allocation), PL_MASK);
	if (is_allocated_flag(scene->allocation, SP_MASK))
		free_dealloc(scene->sp, sizeof(t_sp*), &(scene->allocation), SP_MASK);
	if (is_allocated_flag(scene->allocation, SQ_MASK))
		free_dealloc(scene->sq, sizeof(t_sq*), &(scene->allocation), SQ_MASK);
	if (is_allocated_flag(scene->allocation, CY_MASK))
		free_dealloc(scene->cy, sizeof(t_cy*), &(scene->allocation), CY_MASK);
	if (is_allocated_flag(scene->allocation, TR_MASK))
		free_dealloc(scene->tr, sizeof(t_tr*), &(scene->allocation), TR_MASK);
}
