/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_amb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:51:38 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 18:14:23 by galves-d         ###   ########.fr       */
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
		!valid_num_args(second, 3, 3) || \
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
	char	**first;
	char	**second;
	bool	ret;

	ret = true;
	first = ft_split(tab[1], ',');
	second = ft_split(tab[2], ',');
	if (!in_rangef(ft_atof(first[0]), 0.0, 1.0))
		ret = false;
	else if (!in_range(ft_atoi(second[0]), 0, 255) || \
			!in_range(ft_atoi(second[1]), 0, 255) || \
			!in_range(ft_atoi(second[2]), 0, 255))
		ret = false;
	ft_free_split(&first);
	ft_free_split(&second);
	return (ret);
}

/*
** Function name:
**    validate_amb
** Description:
**    Validate each ambient lighting (A) arguments and parameters
**    Verify if it has none or just one definition
**    Verify if it has the correct number of arguments
**    Verify if each argument has its correct number of parameters
**    Verify if each parameter is in the correct range
** Params:
**    char ***amb -> array of tables (made with ft_split - more info in libft)
**                   each index of the first array (amb[index1]) is a line
**                   (i.e. a different ambient lighting) of the file. At the
**                   second index (amb[index1][index2]) is a word (string) of
**                   the respective line
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [INVALID_QUANTITY_AMB] :: more than one instance of amb.
**       [WRONG_NUM_ARGS_AMB] :: number of arguments don't follow the specified
**       [BAD_FORMAT_AMB] :: some argument has its params bad formatted
**       [WRONG_ARGS_RANGE_AMB] :: some argument is out of range
*/

t_error		validate_amb(char ***amb)
{
	int		i;

	if (!valid_quantity(amb, 0, 1))
		return (INVALID_QUANTITY_AMB);
	i = 0;
	while (amb && amb[i])
	{
		if (!valid_num_args(amb[i], 3, 3))
			return (WRONG_NUM_ARGS_AMB);
		if (!valid_args_num_params(amb[i]))
			return (BAD_FORMAT_AMB);
		if (!valid_args_range(amb[i]))
			return (WRONG_ARGS_RANGE_AMB);
		i++;
	}
	return (NO_ERROR);
}
