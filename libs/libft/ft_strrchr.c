/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:25:53 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:53:37 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		found;
	char	*addr;
	char	trgt;

	i = 0;
	addr = 0;
	found = 0;
	trgt = (char)c;
	while (s[i] != '\0')
	{
		if (s[i++] == trgt)
		{
			found = 1;
			addr = (char *)&s[i - 1];
		}
	}
	if (trgt == '\0')
	{
		found = 1;
		addr = (char *)&s[i];
	}
	if (found)
		return (addr);
	return (0);
}
