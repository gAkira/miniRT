/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 16:58:45 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    valid_num_args
** Description:
**    Verify if the number of arguments passed fits the requirements specified
**    in the project subject
** Params:
**    char **tab -> a line (object) of the file parsed with ft_split (see libft)
**    int min -> min number of arguments acceptable
**    int max -> max number of arguments acceptable
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: number of arguments is not in the range [ 'min' , 'max' ]
**       [true] :: number of arguments is in the range [ 'min' , 'max' ]
*/

static bool	valid_num_args(char **tab, int min, int max)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (in_range(i, min, max));
}

/*
** [STATIC] Function name:
**    valid_args_num_params
** Description:
**    Verify if the number of parameters of each argument fits the requirements
**    specified in the project subject
**    Also verifies if all parameters are numbers or signs
** Params:
**    char **tab -> a line (object) of the file parsed with ft_split (see libft)
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: number of parameters of some argument is not valid
**       [true] :: number of paramenters of all arguments are well formatted
*/

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
		!valid_num_args(second, 3, 3) || \
		!valid_num_args(third, 1, 1) || \
		!are_numerical(first) || \
		!are_numerical(second) || \
		!are_numerical(third))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	return (ret);
}

/*
** [STATIC] Function name:
**    valid_args_range
** Description:
**    Verify if all parameters of all arguments are in the value range specified
**    in the project subject
** Params:
**    char **tab -> a line (object) of the file parsed with ft_split (see libft)
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: some parameter is not in the specified range
**       [true] :: all parameters follow the specified range
*/

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
		!in_rangef(ft_atof(first[2]), -DBL_MAX, DBL_MAX) || \
		!in_rangef(ft_atof(second[0]), -1.0, 1.0) || \
		!in_rangef(ft_atof(second[1]), -1.0, 1.0) || \
		!in_rangef(ft_atof(second[2]), -1.0, 1.0) || \
		!in_rangef(ft_atof(third[0]), 0.0, 180.0))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	ft_free_split(&third);
	return (ret);
}

/*
** Function name:
**    validate_c
** Description:
**    Validate each camera's (c) arguments and parameters
**    Verify if it has the correct number of arguments
**    Verify if each argument has its correct number of parameters
**    Verify if each parameter is in the correct range
** Params:
**    char ***c -> array of tables (made with ft_split - more info in libft)
**                 each index of the first array (c[index1]) is a line
**                 (i.e. a different camera) of the file. At the second
**                 index (c[index1][index2]) is a word (string) of the
**                 respective line
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [WRONG_NUM_ARGS_C] :: wrong number of arguments passed
**       [BAD_FORMAT_C] :: some argument has a wrong number of parameters
**       [WRONG_ARGS_RANGE_C] :: parameter of some argument is out of range
*/

t_error		validate_c(char ***c)
{
	int		i;

	i = 0;
	while (c && c[i])
	{
		if (!valid_num_args(c[i], 4, 4))
			return (WRONG_NUM_ARGS_C);
		if (!valid_args_num_params(c[i]))
			return (BAD_FORMAT_C);
		if (!valid_args_range(c[i]))
			return (WRONG_ARGS_RANGE_C);
		i++;
	}
	return (NO_ERROR);
}
