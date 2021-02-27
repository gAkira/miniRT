/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:05:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/24 23:39:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pwr(int x, int k)
{
	int					i;
	unsigned int		result;

	i = 0;
	result = 1;
	while (i < k)
	{
		result *= (unsigned int)x;
		i++;
	}
	return ((int)result);
}

static void	shift(char *str, char c)
{
	int		i;
	char	aux;

	i = 0;
	while (str[i] != '\0')
	{
		aux = str[i];
		str[i] = c;
		c = aux;
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
}

static int	pop_num(int nbr, char **num)
{
	int				i;
	unsigned int	u_nbr;
	int				signal;

	if (nbr < 0)
		u_nbr = -nbr;
	else
		u_nbr = nbr;
	i = 0;
	while ((u_nbr / pwr(10, i)) > 0)
		i++;
	signal = nbr < 0 ? 1 : 0;
	*num = (char*)malloc((i + 1 + signal) * sizeof(char));
	if (*num == 0)
		return (0);
	(*num)[0] = '\0';
	while (u_nbr > 0)
	{
		shift(*num, u_nbr % 10 + '0');
		u_nbr /= 10;
	}
	if (signal)
		shift(*num, '-');
	return (1);
}

char		*ft_itoa(int nbr)
{
	char	*num;

	if (nbr == 0)
	{
		num = (char*)malloc(2 * sizeof(char));
		if (num != 0)
			ft_strlcpy(num, "0", 2);
		return (num);
	}
	if (nbr == -2147483648)
	{
		num = (char*)malloc(12 * sizeof(char));
		if (num != 0)
			ft_strlcpy(num, "-2147483648", 12);
		return (num);
	}
	if (pop_num(nbr, &num))
		return (num);
	return (0);
}
