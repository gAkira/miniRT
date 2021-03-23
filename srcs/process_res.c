/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 22:23:44 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error	process_res(char ***res, t_scene *scene)
{
	if (!res)
	{
		scene->res.x = 1080;
		scene->res.y = 720;
	}
	else
	{
		scene->res.x = ft_atoi(res[0][1]);
		scene->res.y = ft_atoi(res[0][2]);
	}
	return (NO_ERROR);
}
