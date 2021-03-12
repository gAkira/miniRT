/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 19:52:41 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	valid_num_args(char **tab, int min, int max)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i >= min && i <= max);
}

static bool	valid_args_num_params(char **tab)
{
	char	**first;
	char	**second;
	char	**third;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	third = ft_split(tab[3], ',');
	if (!valid_num_args(first, 3, 3) || \
		!valid_num_args(second, 3, 3) || \
		!valid_num_args(third, 1, 1))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	return (ret);
}

static bool	valid_args_range(char **tab)
{
	char	**first;
	char	**second;
	char	**third;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	third = ft_split(tab[3], ',');
	if (!in_rangef(ft_atof(first[0]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(first[1]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(first[2]), -DBL_MAX, DBL_MAX))
		ret = false;
	else if (!in_rangef(ft_atof(second[0]), -1.0, 1.0) || \
			!in_rangef(ft_atof(second[1]), -1.0, 1.0) || \
			!in_rangef(ft_atof(second[2]), -1.0, 1.0))
		ret = false;
	else if (!in_rangef(ft_atof(third[0]), 0.0, 180.0))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	return (ret);
}

t_error		validate_c(char ***c)
{
	int		i;

	i = 0;
	while (c && c[i])
	{
		if (!valid_num_args(c[i], 4, 4))
			return (WRONG_NUM_ARGS_C);
		if (!valid_args_num_params(c[i]))
			return (BAD_FORMAT_C);
		if (!valid_args_range(c[i]))
			return (WRONG_ARGS_RANGE_C);
		i++;
	}
	return (NO_ERROR);
}
