/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_res_amb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:49:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 23:11:07 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	valid_quantity(char ***file, char *id, int max)
{
	int		i;
	int		id_count;

	i = 0;
	id_count = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i][0], id, ft_strlen(id) + 1))
			id_count++;
		i++;
	}
	return (id_count <= max);
}

static bool	valid_num_args(char ***file, char *id, int num_args)
{
	int	i;
	int	args_len;

	i = 0;
	while (file[i])
	{
		if (!ft_strncmp(file[i][0], id, ft_strlen(id) + 1))
		{
			args_len = 1;
			while (file[i][args_len])
				args_len++;
			args_len--;
			if (args_len != num_args)
				return (false);
		}
		i++;
	}
	return (true);
}

t_error		validate_res_amb(char ***file)
{
	if (!valid_quantity(file, "R", 1))
		return (INVALID_QUANTITY_RES);
	if (!valid_quantity(file, "A", 1))
		return (INVALID_QUANTITY_AMB);
	if (!valid_num_args(file, "R", 2))
		return (WRONG_NUM_ARGS_RES);
	if (!valid_num_args(file, "A", 2))
		return (WRONG_NUM_ARGS_AMB);
	return (NO_ERROR);
}
