/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:28:27 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:40:51 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	u_c;

	i = 0;
	u_c = (unsigned char)c;
	while (i < len)
	{
		*(unsigned char *)(b + i) = u_c;
		i++;
	}
	return (b);
}
