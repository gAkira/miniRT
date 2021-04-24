/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:17:02 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:46:09 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	trgt;

	i = 0;
	trgt = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == trgt)
			return ((char *)(&s[i]));
		i++;
	}
	if (trgt == '\0')
		return ((char *)(&s[i]));
	return (0);
}
