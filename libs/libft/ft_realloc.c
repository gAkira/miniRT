/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:27:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 21:40:26 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
		return (NULL);
	if (!ptr)
		return (ft_calloc(new_size, 1));
	new_ptr = ft_calloc(new_size, 1);
	ft_memmove(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
