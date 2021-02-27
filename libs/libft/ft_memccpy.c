/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:10:30 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/20 17:56:24 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;

	i = 0;
	u_c = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char*)(src + i) == u_c)
		{
			*(unsigned char*)(dst + i) = u_c;
			return (dst + i + 1);
		}
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		i++;
	}
	return (0);
}
