/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:37:01 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:46:36 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	length;

	length = (ft_strlen(s1) + 1) * sizeof(char);
	str = (char *)malloc(length);
	if (str != 0)
		ft_memcpy(str, s1, length);
	return (str);
}
