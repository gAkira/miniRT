/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:14:34 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/27 22:15:14 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r' || c == ' ');
}

int			ft_atoi(const char *str)
{
	int						i;
	int						signal;
	unsigned long long int	result;

	i = 0;
	result = 0;
	signal = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signal = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (unsigned long long int)((result * 10) + (str[i] - '0'));
		i++;
	}
	if (signal < 0 && result > (unsigned long long int)(-(LONG_MIN + 1)) + 1)
		return (0);
	if (signal > 0 && result > (unsigned long long int)LONG_MAX)
		return (-1);
	return ((int)(signal * result));
}
