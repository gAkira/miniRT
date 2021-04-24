/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:56:26 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:40:25 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len && (unsigned long)dst > (unsigned long)src)
	{
		i = 1;
		while (src != dst && i <= len)
		{
			*(unsigned char *)(dst + len - i) = \
											*(unsigned char *)(src + len - i);
			i++;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
