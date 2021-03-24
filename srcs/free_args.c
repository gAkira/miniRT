/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:20:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:05:26 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    free_dealloc
** Description:
**    Free given memory and set its correspondent flag as deallocated
** Params:
**    void *addr -> address to free memory
**    t_args *args -> structure that has the 'allocation' flag
**    size_t mask -> bit number to set as deallocated
** Return:
**    ---
*/

static void	free_dealloc(void *addr, size_t *alloc, t_mask mask)
{
	free(addr);
	deallocate_flag(alloc, mask);
}

/*
** [STATIC] Function name:
**    free_file_and_content
** Description:
**    Free array in which each index is made of a ft_split (more info in libft)
** Params:
**    t_args *args -> struct with an attribute 'file' (array made of ft_split's)
**                    to free each element and itself
** Return:
**    ---
*/

static void	free_file_and_content(t_args *args)
{
	int	i;

	i = 0;
	while (args->file[i])
	{
		ft_free_split(&(args->file[i]));
		i++;
	}
	free_dealloc(args->file, &(args->allocation), FILE_MASK);
}

/*
** Function name:
**    free_args
** Description:
**    Verify what attributes are freed or not (and free it!)
** Params:
**    t_args *args -> structure that must have its attributes freed
** Return:
**    ---
*/

void		free_args(t_args *args)
{
	if (is_allocated_flag(args->allocation, FILENAME_MASK))
		free_dealloc(args->filename, &(args->allocation), FILENAME_MASK);
	if (is_allocated_flag(args->allocation, FILE_MASK))
		free_file_and_content(args);
	if (is_allocated_flag(args->allocation, RES_MASK))
		free_dealloc(args->res, &(args->allocation), RES_MASK);
	if (is_allocated_flag(args->allocation, AMB_MASK))
		free_dealloc(args->amb, &(args->allocation), AMB_MASK);
	if (is_allocated_flag(args->allocation, C_MASK))
		free_dealloc(args->c, &(args->allocation), C_MASK);
	if (is_allocated_flag(args->allocation, L_MASK))
		free_dealloc(args->l, &(args->allocation), L_MASK);
	if (is_allocated_flag(args->allocation, PL_MASK))
		free_dealloc(args->pl, &(args->allocation), PL_MASK);
	if (is_allocated_flag(args->allocation, SP_MASK))
		free_dealloc(args->sp, &(args->allocation), SP_MASK);
	if (is_allocated_flag(args->allocation, SQ_MASK))
		free_dealloc(args->sq, &(args->allocation), SQ_MASK);
	if (is_allocated_flag(args->allocation, CY_MASK))
		free_dealloc(args->cy, &(args->allocation), CY_MASK);
	if (is_allocated_flag(args->allocation, TR_MASK))
		free_dealloc(args->tr, &(args->allocation), TR_MASK);
}
