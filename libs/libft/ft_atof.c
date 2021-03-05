/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:38:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/02 21:47:38 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	get_number(const char *s, int *new_i)
{
	int		i;
	double	num;

	i = 0;
	num = 0.0;
	while (ft_isdigit(s[i]))
		num = 10.0 * num + (double)(s[i++] - '0');
	*new_i += i;
	return (num);
}

static double	my_pow(int num, int exp)
{
	int		i;
	int		exp_neg;
	double	res;

	i = 0;
	res = 1.0;
	exp_neg = 0;
	if (exp < 0)
	{
		exp_neg = 1;
		exp = -exp;
	}
	while (i < exp)
	{
		res *= (double)num;
		i++;
	}
	if (exp_neg)
		res = 1.0 / res;
	return (res);
}

static double	get_decimal(const char *s)
{
	int		i;
	double	dec;

	i = 0;
	dec = 0.0;
	if (!s || !s[i++])
		return (dec);
	while (ft_isdigit(s[i]))
	{
		dec += (double)(s[i] - '0') * my_pow(10, -i);
		i++;
	}
	return (dec);
}

double			ft_atof(const char *s)
{
	int		i;
	int		is_neg;
	double	num;

	i = 0;
	is_neg = 0;
	if (!s)
		return (0.0);
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	while (s[i] && (s[i] == '+' || s[i] == '-'))
		if (s[i++] == '-')
			is_neg = !is_neg;
	num = get_number(&s[i], &i);
	num += get_decimal(&s[i]);
	if (is_neg)
		num = -num;
	return (num);
}
