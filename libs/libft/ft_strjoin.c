/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:16:16 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:46:52 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (s1 == 0 || s2 == 0)
		return (0);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join != 0)
	{
		ft_strlcpy(join, s1, ft_strlen(s1) + 1);
		ft_strlcpy(join + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	return (join);
}
