/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:57:04 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	allocate_in_scene(char ***l, t_scene *scene)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	if (!(scene->l = (t_l*)ft_calloc(i + 1, sizeof(t_l))))
		return (false);
	scene->l[i].end = true;
	allocate_flag(&(scene->allocation), L_MASK);
	return (true);
}

static void	put_in_scene(char ***l, char ***params, t_scene *scene, int i)
{
	scene->l[i].coord = vec3(ft_atof(params[0][0]), \
							ft_atof(params[0][1]), \
							ft_atof(params[0][2]));
	scene->l[i].ratio = ft_atof(l[i][2]);
	scene->l[i].color = vec3_int(ft_atoi(params[1][0]), \
								ft_atoi(params[1][1]), \
								ft_atoi(params[1][2]));
}

static bool	params_in_scene(char ***l, t_scene *scene, int i)
{
	char **params[2];

	ft_bzero(&params, 2 * sizeof(char**));
	if (!(params[0] = ft_split(l[i][1], ',')) || \
		!(params[1] = ft_split(l[i][3], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		return (false);
	}
	put_in_scene(l, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	return (true);
}

t_error		process_l(char ***l, t_scene *scene)
{
	int		i;

	if (!l)
		return (NO_ERROR);
	if (!allocate_in_scene(l, scene))
		return (NO_MEMORY);
	i = 0;
	while (l[i])
		if (!params_in_scene(l, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
