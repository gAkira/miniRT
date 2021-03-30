/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_tr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 21:28:25 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	allocate_in_scene(char ***tr, t_scene *scene)
{
	int	i;

	i = 0;
	while (tr[i])
		i++;
	if (!(scene->tr = (t_tr**)ft_calloc(i + 1, sizeof(t_tr*))))
		return (false);
	allocate_flag(&(scene->allocation), TR_MASK);
	i = 0;
	while (tr[i])
		if (!(scene->tr[i++] = (t_tr*)ft_calloc(1, sizeof(t_tr))))
			return (false);
	return (true);
}

static void	put_in_scene(char ***tr, char ***params, t_scene *scene, int i)
{
	(void)tr;
	scene->tr[i]->coord[0] = mx_point(ft_atof(params[0][0]), \
									ft_atof(params[0][1]), \
									ft_atof(params[0][2]));
	scene->tr[i]->coord[1] = mx_point(ft_atof(params[1][0]), \
									ft_atof(params[1][1]), \
									ft_atof(params[1][2]));
	scene->tr[i]->coord[2] = mx_point(ft_atof(params[2][0]), \
									ft_atof(params[2][1]), \
									ft_atof(params[2][2]));
	scene->tr[i]->color = mx_vector(ft_atoi(params[3][0]), \
									ft_atoi(params[3][1]), \
									ft_atoi(params[3][2]));
}

static bool	params_in_scene(char ***tr, t_scene *scene, int i)
{
	char **params[4];

	ft_bzero(&params, 4 * sizeof(char**));
	if (!(params[0] = ft_split(tr[i][1], ',')) || \
		!(params[1] = ft_split(tr[i][2], ',')) || \
		!(params[2] = ft_split(tr[i][3], ',')) || \
		!(params[3] = ft_split(tr[i][4], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		ft_free_split(&(params[2]));
		ft_free_split(&(params[3]));
		return (false);
	}
	put_in_scene(tr, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	ft_free_split(&(params[2]));
	ft_free_split(&(params[3]));
	return (true);
}

t_error		process_tr(char ***tr, t_scene *scene)
{
	int		i;

	if (!tr)
		return (NO_ERROR);
	if (!allocate_in_scene(tr, scene))
		return (NO_MEMORY);
	i = 0;
	while (tr[i])
		if (!params_in_scene(tr, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
