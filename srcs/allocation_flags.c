/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:34:26 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/13 21:34:26 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    allocate_flag
** Description:
**    Given a number mask, bitwises a 1 to the respective bit in *alloc
** Params:
**    size_t *alloc -> pointer location to allocate
**    size_t mask -> bit number in which must put the bit 1
** Return:
**    ---
*/

void	allocate_flag(size_t *alloc, size_t mask)
{
	*alloc |= (1 << mask);
}

/*
** Function name:
**    deallocate_flag
** Description:
**    Given a number mask, bitwises a 0 to the respective bit in *alloc
** Params:
**    size_t *alloc -> pointer location to allocate
**    size_t mask -> bit number in which must put the bit 0
** Return:
**    ---
*/

void	deallocate_flag(size_t *alloc, size_t mask)
{
	*alloc &= ~(1 << mask);
}

/*
** Function name:
**    is_allocated_flag
** Description:
**    Given a number mask, verify current value of the respective bit in alloc
** Params:
**    size_t alloc -> value to verify the bits
**    size_t mask -> bit number in which must put the bit 0
** Return:
**    bool -> value of the bit asked in mask
**       [false] :: bit was 0
**       [true] :: bit was 1
*/

bool	is_allocated_flag(size_t alloc, size_t mask)
{
	return (!!(alloc & (1 << mask)));
}
