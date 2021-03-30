/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 19:02:33 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	allocate_in_scene(char ***c, t_scene *scene)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	if (!(scene->c = (t_c**)ft_calloc(i + 1, sizeof(t_c*))))
		return (false);
	allocate_flag(&(scene->allocation), C_MASK);
	i = 0;
	while (c[i])
		if (!(scene->c[i++] = (t_c*)ft_calloc(1, sizeof(t_c))))
			return (false);
	return (true);
}

static void	put_in_scene(char ***c, char ***params, t_scene *scene, int i)
{
	scene->c[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->c[i]->dir = mx_vector(ft_atof(params[1][0]), \
								ft_atof(params[1][1]), \
								ft_atof(params[1][2]));
	scene->c[i]->fov = ft_atoi(c[i][3]);
}

static bool	params_in_scene(char ***c, t_scene *scene, int i)
{
	char	**params[2];

	ft_bzero(&params, 2 * sizeof(char**));
	if (!(params[0] = ft_split(c[i][1], ',')) || \
		!(params[1] = ft_split(c[i][2], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		return (false);
	}
	put_in_scene(c, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	return (true);
}

t_error		process_c(char ***c, t_scene *scene)
{
	int		i;

	if (!c)
		return (NO_ERROR);
	if (!allocate_in_scene(c, scene))
		return (NO_MEMORY);
	i = 0;
	while (c[i])
		if (!params_in_scene(c, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
