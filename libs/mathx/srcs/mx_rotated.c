/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_rotated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:37:07 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 04:41:04 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathx.h"

t_matrix	mx_xrotated(double deg)
{
	double	rad;

	rad = (deg / 180.0) * M_PI;
	return (mx_xrotate(rad));
}

t_matrix	mx_yrotated(double deg)
{
	double	rad;

	rad = (deg / 180.0) * M_PI;
	return (mx_yrotate(rad));
}

t_matrix	mx_zrotated(double deg)
{
	double	rad;

	rad = (deg / 180.0) * M_PI;
	return (mx_zrotate(rad));
}
