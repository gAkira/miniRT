/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:20:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/13 21:53:37 by galves-d         ###   ########.fr       */
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

static void	free_dealloc(void *addr, t_args *args, size_t mask)
{
	free(addr);
	deallocate_flag(&(args->allocation), mask);
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
	free_dealloc(args->file, args, ARGS_FILE);
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
	if (is_allocated_flag(args->allocation, ARGS_FILENAME))
		free_dealloc(args->filename, args, ARGS_FILENAME);
	if (is_allocated_flag(args->allocation, ARGS_FILE))
		free_file_and_content(args);
	if (is_allocated_flag(args->allocation, ARGS_RES))
		free_dealloc(args->res, args, ARGS_RES);
	if (is_allocated_flag(args->allocation, ARGS_AMB))
		free_dealloc(args->amb, args, ARGS_AMB);
	if (is_allocated_flag(args->allocation, ARGS_C))
		free_dealloc(args->c, args, ARGS_C);
	if (is_allocated_flag(args->allocation, ARGS_L))
		free_dealloc(args->l, args, ARGS_L);
	if (is_allocated_flag(args->allocation, ARGS_PL))
		free_dealloc(args->pl, args, ARGS_PL);
	if (is_allocated_flag(args->allocation, ARGS_SP))
		free_dealloc(args->sp, args, ARGS_SP);
	if (is_allocated_flag(args->allocation, ARGS_SQ))
		free_dealloc(args->sq, args, ARGS_SQ);
	if (is_allocated_flag(args->allocation, ARGS_CY))
		free_dealloc(args->cy, args, ARGS_CY);
	if (is_allocated_flag(args->allocation, ARGS_TR))
		free_dealloc(args->tr, args, ARGS_TR);
}
