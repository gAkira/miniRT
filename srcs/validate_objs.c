/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:21:15 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 17:52:27 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    valid_identifiers
** Description:
**    Verify if all lines of the file starts with a known (valid) identifier
**    All valid identifiers at incs/arguments.h -> VALID_IDENTIFIERS
** Params:
**    char ***file -> each non-empty line of the file in one index (file[index])
**                    and its content splitted by ft_split (see libft)
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: an invalid identifier has been found
**       [true] :: all identifiers are valid
*/

static bool	valid_identifiers(char ***file)
{
	int		i;
	int		k;
	bool	is_valid;
	char	**ids;

	ids = ft_split(VALID_IDENTIFIERS, ',');
	i = 0;
	while (file[i])
	{
		k = 0;
		is_valid = false;
		while (ids[k++])
			if (!ft_strncmp(file[i][0], ids[k - 1], ft_strlen(ids[k - 1]) + 1))
				is_valid = true;
		if (file[i][0][0] == '#')
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

/*
** [STATIC] Function name:
**    store_id
** Description:
**    Increment the respective list of elements (args->'list') and then makes
**    the last element point to the correspondent line in file
**    After that set the correct flag allocation
** Params:
**    char ****list -> address of the list of elements to increase
**    char **new -> line to add at the end of the list
**    t_args *args -> structure to allocate the respective flag
**    size_t mask -> mask to set allocation
** Return:
**    ---
*/

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

/*
** [STATIC] Function name:
**    organize_identifiers
** Description:
**    Associate each line of the file to its respective list attribute in args
** Params:
**    t_args *args -> structure containing the file content and each respective
**                    attribute of id list
** Return:
**    ---
*/

static void	organize_identifiers(t_args *args)
{
	int	i;

	i = 0;
	while (args->file[i++])
	{
		if (!ft_strncmp(args->file[i - 1][0], "R", ft_strlen("R") + 1))
			store_id(&(args->res), args->file[i - 1], args, RES_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "A", ft_strlen("A") + 1))
			store_id(&(args->amb), args->file[i - 1], args, AMB_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "c", ft_strlen("c") + 1))
			store_id(&(args->c), args->file[i - 1], args, C_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "l", ft_strlen("l") + 1))
			store_id(&(args->l), args->file[i - 1], args, L_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "pl", ft_strlen("pl") + 1))
			store_id(&(args->pl), args->file[i - 1], args, PL_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "sp", ft_strlen("sp") + 1))
			store_id(&(args->sp), args->file[i - 1], args, SP_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "sq", ft_strlen("sq") + 1))
			store_id(&(args->sq), args->file[i - 1], args, SQ_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "cy", ft_strlen("cy") + 1))
			store_id(&(args->cy), args->file[i - 1], args, CY_MASK);
		else if (!ft_strncmp(args->file[i - 1][0], "tr", ft_strlen("tr") + 1))
			store_id(&(args->tr), args->file[i - 1], args, TR_MASK);
	}
}

/*
** Function name:
**    validate_objs
** Description:
**    Verify if all identifiers of the file are valid
**    Organizes each identifier in its respective attribute
**    Call validation function of each identifier
** Params:
**    t_args *args -> structure containing the file content and each respective
**                    attribute of id list
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [INVALID_IDENTIFIER] :: there's some invalid identifier in the file
**       other values :: each function return the correspondent error value
*/

t_error		validate_objs(t_args *args)
{
	t_error	error;

	if (!valid_identifiers(args->file))
		return (INVALID_IDENTIFIER);
	organize_identifiers(args);
	error = NO_ERROR;
	if ((error = validate_res(args->res)) || \
		(error = validate_amb(args->amb)) || \
		(error = validate_c(args->c)) || \
		(error = validate_l(args->l)) || \
		(error = validate_sp(args->sp)) || \
		(error = validate_pl(args->pl)) || \
		(error = validate_sq(args->sq)) || \
		(error = validate_cy(args->cy)) || \
		(error = validate_tr(args->tr)))
		return (error);
	return (error);
}
