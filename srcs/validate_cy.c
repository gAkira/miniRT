/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 22:56:59 by galves-d         ###   ########.fr       */
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
	int		i;
	char	**params[5];
	bool	ret;

	ret = true;
	i = 0;
	while (i++ < 5)
		params[i - 1] = ft_split(tab[i], ',');
	if (!valid_num_args(params[0], 3, 3) || \
		!valid_num_args(params[1], 3, 3) || \
		!valid_num_args(params[2], 1, 1) || \
		!valid_num_args(params[3], 1, 1) || \
		!valid_num_args(params[4], 3, 3))
		ret = false;
	i = 0;
	while (i++ < 5)
		ft_free_split(&(params[i - 1]));
	return (ret);
}

static bool	valid_args_range(char **tab)
{
	int		i;
	char	**params[5];
	bool	ret;

	ret = true;
	i = 0;
	while (i++ < 5)
		params[i - 1] = ft_split(tab[i], ',');
	if (!in_rangef(ft_atof(params[0][0]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[0][1]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[0][2]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(params[1][0]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[1][1]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[1][2]), -1.0, 1.0) || \
		!in_rangef(ft_atof(params[2][0]), 0.0, DBL_MAX) || \
		!in_rangef(ft_atof(params[3][0]), 0.0, DBL_MAX) || \
		!in_range(ft_atoi(params[4][0]), 0, 255) || \
		!in_range(ft_atoi(params[4][1]), 0, 255) || \
		!in_range(ft_atoi(params[4][2]), 0, 255))
		ret = false;
	i = 0;
	while (i++ < 5)
		ft_free_split(&(params[i - 1]));
	return (ret);
}

t_error		validate_cy(char ***cy)
{
	int		i;

	i = 0;
	while (cy && cy[i])
	{
		if (!valid_num_args(cy[i], 6, 6))
			return (WRONG_NUM_ARGS_CY);
		if (!valid_args_num_params(cy[i]))
			return (BAD_FORMAT_CY);
		if (!valid_args_range(cy[i]))
			return (WRONG_ARGS_RANGE_CY);
		i++;
	}
	return (NO_ERROR);
}
