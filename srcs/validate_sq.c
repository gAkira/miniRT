/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 22:12:11 by galves-d         ###   ########.fr       */
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
	char	**fourth;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	third = ft_split(tab[3], ',');
	fourth = ft_split(tab[4], ',');
	if (!valid_num_args(first, 3, 3) || \
		!valid_num_args(second, 3, 3) || \
		!valid_num_args(third, 1, 1) || \
		!valid_num_args(fourth, 3, 3))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	ft_free_split(&fourth);
	return (ret);
}

static bool	valid_args_range(char **tab)
{
	int		i;
	char	**params[4];
	bool	ret;

	ret = true;
	i = 0;
	while (i++ < 4)
		params[i - 1] = ft_split(tab[i], ',');
	if (!in_rangef(ft_atof(params[0][0]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[0][1]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[0][2]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[1][0]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[1][1]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[1][2]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[2][0]), 0.0, DBL_MAX) || \
		!in_range(ft_atoi(params[3][0]), 0, 255) || \
		!in_range(ft_atoi(params[3][1]), 0, 255) || \
		!in_range(ft_atoi(params[3][2]), 0, 255))
		ret = false;
	i = 0;
	while (i++ < 4)
		ft_free_split(&(params[i - 1]));
	return (ret);
}

t_error		validate_sq(char ***sq)
{
	int		i;

	i = 0;
	while (sq && sq[i])
	{
		if (!valid_num_args(sq[i], 5, 5))
			return (WRONG_NUM_ARGS_SQ);
		if (!valid_args_num_params(sq[i]))
			return (BAD_FORMAT_SQ);
		if (!valid_args_range(sq[i]))
			return (WRONG_ARGS_RANGE_SQ);
		i++;
	}
	return (NO_ERROR);
}
