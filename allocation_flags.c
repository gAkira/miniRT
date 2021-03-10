/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:34:26 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 17:18:24 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	allocate_flag(size_t *alloc, size_t mask)
{
	*alloc |= mask;
}

void	deallocate_flag(size_t *alloc, size_t mask)
{
	*alloc &= ~mask;
}

bool	is_allocated_flag(size_t alloc, size_t mask)
{
	return (!!(alloc & mask));
}
