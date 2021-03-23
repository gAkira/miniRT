/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 18:22:42 by galves-d         ###   ########.fr       */
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
	if (!valid_num_args(first, 1, 1) || !valid_num_args(second, 1, 1))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	return (ret);
}

static bool	valid_args_range(char **tab)
{
	bool	ret;

	ret = true;
	if (!in_range(ft_atoi(tab[1]), 1, INT_MAX))
		ret = false;
	else if (!in_range(ft_atoi(tab[2]), 1, INT_MAX))
		ret = false;
	return (ret);
}

t_error		validate_res(char ***res)
{
	int		i;

	if (!valid_quantity(res, 0, 1))
		return (INVALID_QUANTITY_RES);
	i = 0;
	while (res && res[i])
	{
		if (!valid_num_args(res[i], 3, 3))
			return (WRONG_NUM_ARGS_RES);
		if (!valid_args_num_params(res[i]))
			return (BAD_FORMAT_RES);
		if (!valid_args_range(res[i]))
			return (WRONG_ARGS_RANGE_RES);
		i++;
	}
	return (NO_ERROR);
}
