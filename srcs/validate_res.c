/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 18:11:26 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    valid_quantity
** Description:
**    Verifies if the quantity of elements of the 3D table 'tab' is inside
**    the range of [ 'min' , 'max' ]
** Params:
**    char ***tab -> table to test its length
**    int min -> lower bound of the interval
**    int max -> upper bound of the interval
** Return:
**    bool -> says whether the length is inside or not of the closed interval
**       [false] :: the number is not inside of the interval
**       [true] :: the number is inside or on the boundary of the interval
*/

static bool	valid_quantity(char ***tab, int min, int max)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (in_range(i, min, max));
}

/*
** [STATIC] Function name:
**    valid_num_args
** Description:
**    Verifies if the number of arguments (lines) of the 2D table 'tab'
**    is inside the range of [ 'min' , 'max' ]
** Params:
**    char **tab -> table to test its "height" (number of lines/args)
**    int min -> lower bound of the interval
**    int max -> upper bound of the interval
** Return:
**    bool -> says whether the height is inside or not of the closed interval
**       [false] :: the number is not inside of the interval
**       [true] :: the number is inside or on the boundary of the interval
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
**    Verifies if each argument has its correct number of parameters specified
**    in the project
**    Also verifies if all parameters are numbers or signs
** Params:
**    char **tab -> table to test each args' amount of params
** Return:
**    bool -> says whether all arguments are correct or not
**       [false] :: some argument is out of its specifications
**       [true] :: all arguments are well formatted
*/

static bool	valid_args_num_params(char **tab)
{
	char	**first;
	char	**second;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	if (!valid_num_args(first, 1, 1) || \
		!valid_num_args(second, 1, 1) || \
		!are_numerical(first) || \
		!are_numerical(second))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	return (ret);
}

/*
** [STATIC] Function name:
**    valid_args_range
** Description:
**    Verifies if each argument's parameter is inside its range specified
**    in the project
** Params:
**    char **tab -> table to test each args' parameter
** Return:
**    bool -> says whether all parameters are correct or not
**       [false] :: some parameter is out of range
**       [true] :: all parameters are well fit in its designed range
*/

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

/*
** Function name:
**    validate_res
** Description:
**    Validate each resolution (R) arguments and parameters
**    Verify if it has none or just one definition
**    Verify if it has the correct number of arguments
**    Verify if each argument has its correct number of parameters
**    Verify if each parameter is in the correct range
** Params:
**    char ***res -> array of tables (made with ft_split - more info in libft)
**                   each index of the first array (res[index1]) is a line
**                   (i.e. a different resolution) of the file. At the second
**                   index (res[index1][index2]) is a word (string) of the
**                   respective line
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [INVALID_QUANTITY_RES] :: more than one instance of amb.
**       [WRONG_NUM_ARGS_RES] :: number of arguments don't follow the specified
**       [BAD_FORMAT_RES] :: some argument has its params bad formatted
**       [WRONG_ARGS_RANGE_RES] :: some argument is out of range
*/

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
