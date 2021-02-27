/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:39:45 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/26 01:16:30 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	size_t		s_len;
	char		*sub;

	length = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s + start);
	if (start < ft_strlen(s))
		length = (len > s_len ? s_len : len);
	sub = (char*)malloc((length + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, &s[start], (length + 1) * sizeof(char));
	return (sub);
}
