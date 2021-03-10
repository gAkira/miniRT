/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:20:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 20:10:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_dealloc(void *addr, t_args *args, size_t mask)
{
	free(addr);
	deallocate_flag(&(args->allocation), mask);
}

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
