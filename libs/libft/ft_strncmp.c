/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:26:08 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:49:15 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	i = 0;
	diff = 0;
	while (i < n && !diff && s1[i] != '\0' && s2[i] != '\0')
	{
		diff = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && !diff && (s1[i] == '\0' || s2[i] == '\0'))
		diff = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (diff);
}
