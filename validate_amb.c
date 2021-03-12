/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 19:49:29 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	valid_quantity(char ***tab, int min, int max)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i >= min && i <= max);
}

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
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	if (!valid_num_args(first, 1, 1) || \
		!valid_num_args(second, 3, 3))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	return (ret);
}

static bool	valid_args_range(char **tab)
{
	char	**first;
	char	**second;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	if (!in_rangef(ft_atof(first[0]), 0.0, 1.0))
		ret = false;
	else if (!in_range(ft_atoi(second[0]), 0, 255) || \
			!in_range(ft_atoi(second[1]), 0, 255) || \
			!in_range(ft_atoi(second[2]), 0, 255))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	return (ret);
}

t_error		validate_amb(char ***amb)
{
	int		i;

	if (!valid_quantity(amb, 0, 1))
		return (INVALID_QUANTITY_AMB);
	i = 0;
	while (amb && amb[i])
	{
		if (!valid_num_args(amb[i], 3, 3))
			return (WRONG_NUM_ARGS_AMB);
		if (!valid_args_num_params(amb[i]))
			return (BAD_FORMAT_AMB);
		if (!valid_args_range(amb[i]))
			return (WRONG_ARGS_RANGE_AMB);
		i++;
	}
	return (NO_ERROR);
}
