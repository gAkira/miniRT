/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 23:17:19 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:47:44 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (dst == 0 || src == 0)
		return (0);
	len = 0;
	while (dst != src && src[len] != '\0')
		len++;
	i = 0;
	while (dst != src && dstsize && src[i] != '\0' && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (len);
}
