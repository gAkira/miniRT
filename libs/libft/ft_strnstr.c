/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 04:36:02 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/23 15:28:33 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len && haystack[i] != '\0')
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			while ((i + k) < len && needle[k] != '\0' &&
					haystack[i + k] == needle[k])
				k++;
			if (needle[k] == '\0')
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (0);
}
