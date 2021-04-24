/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:07:43 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:55:18 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_on_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*create_substr(char const *s1, size_t start, size_t end)
{
	char	*sub;
	size_t	len;

	if (end > start)
		len = end - start + 1;
	else
		len = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub != 0)
	{
		if (len == 0)
			sub[0] = '\0';
		else
			ft_strlcpy(sub, &s1[start], len + 1);
	}
	return (sub);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (s1[i] != '\0' && is_on_set(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && is_on_set(s1[i], set))
		i--;
	end = i;
	return (create_substr(s1, start, end));
}
