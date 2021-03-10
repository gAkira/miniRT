/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:21:15 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 20:01:08 by galves-d         ###   ########.fr       */
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

static void	store_id(char ****list, char **new, t_args *args, size_t mask)
{
	int	i;

	i = 0;
	while (list && *list && (*list)[i])
		i++;
	*list = (char***)ft_realloc(*list, (i + !!(*list)) * sizeof(char**), \
						(i + 2) * sizeof(char**));
	(*list)[i] = new;
	allocate_flag(&(args->allocation), mask);
}

static void	organize_identifiers(t_args *args)
{
	int	i;

	i = 0;
	while (args->file[i++])
	{
		if (!ft_strncmp(args->file[i - 1][0], "R", ft_strlen("R") + 1))
			store_id(&(args->res), args->file[i - 1], args, ARGS_RES);
		else if (!ft_strncmp(args->file[i - 1][0], "A", ft_strlen("A") + 1))
			store_id(&(args->amb), args->file[i - 1], args, ARGS_AMB);
		else if (!ft_strncmp(args->file[i - 1][0], "c", ft_strlen("c") + 1))
			store_id(&(args->c), args->file[i - 1], args, ARGS_C);
		else if (!ft_strncmp(args->file[i - 1][0], "l", ft_strlen("l") + 1))
			store_id(&(args->l), args->file[i - 1], args, ARGS_L);
		else if (!ft_strncmp(args->file[i - 1][0], "pl", ft_strlen("pl") + 1))
			store_id(&(args->pl), args->file[i - 1], args, ARGS_PL);
		else if (!ft_strncmp(args->file[i - 1][0], "sp", ft_strlen("sp") + 1))
			store_id(&(args->sp), args->file[i - 1], args, ARGS_SP);
		else if (!ft_strncmp(args->file[i - 1][0], "sq", ft_strlen("sq") + 1))
			store_id(&(args->sq), args->file[i - 1], args, ARGS_SQ);
		else if (!ft_strncmp(args->file[i - 1][0], "cy", ft_strlen("cy") + 1))
			store_id(&(args->cy), args->file[i - 1], args, ARGS_CY);
		else if (!ft_strncmp(args->file[i - 1][0], "tr", ft_strlen("tr") + 1))
			store_id(&(args->tr), args->file[i - 1], args, ARGS_TR);
	}
}

t_error		validate_objs(t_args *args)
{
	t_error	error;

	if (!valid_identifiers(args->file))
		return (INVALID_IDENTIFIER);
	organize_identifiers(args);
	if (!(error = validate_res_amb(args->file)))
		return (error);
	return (error);
}
