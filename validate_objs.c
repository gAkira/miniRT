/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:49:25 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 21:47:37 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	valid_identifiers(char ***file)
{
	int		i;
	int		k;
	bool	is_valid;
	char	**ids;

	ids = ft_split(IDENTIFIERS, ',');
	i = 0;
	while (file[i])
	{
		k = 0;
		is_valid = false;
		while (ids[k++])
			if (!ft_strncmp(file[i][0], ids[k - 1], ft_strlen(ids[k - 1]) + 1))
				is_valid = true;
		if (!is_valid)
		{
			ft_free_split(&ids);
			return (false);
		}
		i++;
	}
	ft_free_split(&ids);
	return (true);
}

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

t_error		validate_res_amb(char ***file)
{
	if (!valid_identifiers(file))
		return (INVALID_IDENTIFIER);
	if (!valid_quantity(file, "R", 1))
		return (INVALID_QUANTITY_RES);
	if (!valid_quantity(file, "A", 1))
		return (INVALID_QUANTITY_AMB);
	return (NO_ERROR);
}
