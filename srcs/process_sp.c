/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 21:28:52 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	allocate_in_scene(char ***sp, t_scene *scene)
{
	int	i;

	i = 0;
	while (sp[i])
		i++;
	if (!(scene->sp = (t_sp**)ft_calloc(i + 1, sizeof(t_sp*))))
		return (false);
	allocate_flag(&(scene->allocation), SP_MASK);
	i = 0;
	while (sp[i])
		if(!(scene->sp[i++] = (t_sp*)ft_calloc(1, sizeof(t_sp))))
			return (false);
	return (true);
}

static void	put_in_scene(char ***sp, char ***params, t_scene *scene, int i)
{
	scene->sp[i]->coord = mx_point(ft_atof(params[0][0]), \
								ft_atof(params[0][1]), \
								ft_atof(params[0][2]));
	scene->sp[i]->diam = ft_atof(sp[i][2]);
	scene->sp[i]->color = mx_vector(ft_atoi(params[1][0]), \
								ft_atoi(params[1][1]), \
								ft_atoi(params[1][2]));
}

static bool	params_in_scene(char ***sp, t_scene *scene, int i)
{
	char **params[2];

	ft_bzero(&params, 2 * sizeof(char**));
	if (!(params[0] = ft_split(sp[i][1], ',')) || \
		!(params[1] = ft_split(sp[i][3], ',')))
	{
		ft_free_split(&(params[0]));
		ft_free_split(&(params[1]));
		return (false);
	}
	put_in_scene(sp, params, scene, i);
	ft_free_split(&(params[0]));
	ft_free_split(&(params[1]));
	return (true);
}

t_error		process_sp(char ***sp, t_scene *scene)
{
	int		i;

	if (!sp)
		return (NO_ERROR);
	if (!allocate_in_scene(sp, scene))
		return (NO_MEMORY);
	i = 0;
	while (sp[i])
		if (!params_in_scene(sp, scene, i++))
			return (NO_MEMORY);
	return (NO_ERROR);
}
