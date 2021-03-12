/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 21:22:40 by galves-d         ###   ########.fr       */
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
		!valid_num_args(second, 1, 1) || \
		!valid_num_args(third, 3, 3))
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
	else if (!in_rangef(ft_atof(second[0]), 0.0, DBL_MAX))
		ret = false;
	else if (!in_range(ft_atoi(third[0]), 0, 255) || \
			!in_range(ft_atoi(third[1]), 0, 255) || \
			!in_range(ft_atoi(third[2]), 0, 255))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	return (ret);
}

t_error		validate_sp(char ***sp)
{
	int		i;

	i = 0;
	while (sp && sp[i])
	{
		if (!valid_num_args(sp[i], 4, 4))
			return (WRONG_NUM_ARGS_SP);
		if (!valid_args_num_params(sp[i]))
			return (BAD_FORMAT_SP);
		if (!valid_args_range(sp[i]))
			return (WRONG_ARGS_RANGE_SP);
		i++;
	}
	return (NO_ERROR);
}
