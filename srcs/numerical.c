/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:17:34 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 18:57:52 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    is_numerical
** Description:
**    Verify if all characters of the string is a digit or a
**    sign character ('+' or '-')
** Params:
**    char *str -> a string
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: some character is not numerical nor a sign
**       [true] :: all characteres are numerical and/or a sign
*/

bool	is_numerical(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || \
				str[i] == '.' || \
				str[i] == '-' || \
				str[i] == '+'))
			return (false);
		i++;
	}
	return (true);
}

/*
** Function name:
**    are_numerical
** Description:
**    Verify if all characters of each line in the table
**    is a digit or a sign character ('+' or '-')
** Params:
**    char **tab -> a table made with ft_split (see libft)
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: some character is not numerical nor a sign
**       [true] :: all characteres are numerical and/or a sign
*/

bool	are_numerical(char **tab)
{
	int	i;

	if (!tab)
		return (false);
	i = 0;
	while (tab[i])
		if (!is_numerical(tab[i++]))
			return (false);
	return (true);
}
