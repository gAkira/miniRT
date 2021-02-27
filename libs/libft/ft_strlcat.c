/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:09:02 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/23 14:39:11 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_src = 0;
	len_dst = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	i = len_dst;
	while (dstsize && src[i - len_dst] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	if (len_dst < dstsize)
		dst[i] = '\0';
	return (len_dst + len_src);
}
