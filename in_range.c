/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 22:13:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 22:18:00 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	in_range(int num, int min, int max)
{
	return (num >= min && num <= max);
}

bool	in_rangef(double num, double min, double max)
{
	return (num >= min && num <= max);
}
