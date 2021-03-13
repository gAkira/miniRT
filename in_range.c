/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:13:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/13 22:04:30 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    in_range
** Description:
**    Verifies whether a given integer number 'num' is inside a
**    closed interval [ 'min' , 'max' ]
** Params:
**    int num -> number to test
**    int min -> lower bound of the interval
**    int max -> upper bound of the interval
** Return:
**    bool -> says whether the number is inside or not of the closed interval
**       [false] :: the number is not inside of the interval
**       [true] :: the number is inside or on the boundary of the interval
*/

bool	in_range(int num, int min, int max)
{
	return (num >= min && num <= max);
}

/*
** Function name:
**    in_rangef
** Description:
**    Floating-point version of the in_range function
**    Verifies whether a given floating-point number 'num' is inside a
**    closed interval [ 'min' , 'max' ]
** Params:
**    double num -> number to test
**    double min -> lower bound of the interval
**    double max -> upper bound of the interval
** Return:
**    bool -> says whether the number is inside or not of the closed interval
**       [false] :: the number is not inside of the interval
**       [true] :: the number is inside or on the boundary of the interval
*/

bool	in_rangef(double num, double min, double max)
{
	return (num >= min && num <= max);
}
