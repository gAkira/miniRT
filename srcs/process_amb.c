/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_amb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 22:36:13 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_error	process_amb(char ***amb, t_scene *scene)
{
	char	**params;

	if (!amb)
	{
		scene->amb.ratio = 0.0;
		scene->amb.color = vec3_int(0, 0, 0);
	}
	else
	{
		if (!(params = ft_split(amb[0][2], ',')))
			return (NO_MEMORY);
		scene->amb.ratio = ft_atof(amb[0][1]);
		scene->amb.color = vec3_int(ft_atoi(params[0]), \
									ft_atoi(params[1]), \
									ft_atoi(params[2]));
		ft_free_split(&params);
	}
	return (NO_ERROR);
}
