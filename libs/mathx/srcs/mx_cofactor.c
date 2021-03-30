/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_cofactor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:18:27 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/29 20:25:06 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

double	mx_cofactor(t_matrix a, size_t row, size_t col)
{
	if ((row + col) % 2)
		return (-mx_minor(a, row, col));
	return (mx_minor(a, row, col));
}
