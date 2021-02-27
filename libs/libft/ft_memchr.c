/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:30:41 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/21 22:03:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u_c;

	i = 0;
	u_c = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char*)(s + i) == u_c)
			return ((void*)(s + i));
		i++;
	}
	return (0);
}
