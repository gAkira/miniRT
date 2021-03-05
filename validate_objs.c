/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:21:15 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 23:10:21 by galves-d         ###   ########.fr       */
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

t_error		validate_objs(char ***file)
{
	t_error	error;

	if (!valid_identifiers(file))
		return (INVALID_IDENTIFIER);
	if (!(error = validate_res_amb(file)))
		return (error);
	return (error);
}
