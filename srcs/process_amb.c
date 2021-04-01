/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_amb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 20:57:54 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    process_amb
** Description:
**    Process each ambient lighting (A) arguments and parameters
**    If there's no instance of amb (A) in the scene file, it assumes:
**        ratio = 0.0
**        color = (0.0 , 0.0 , 0.0)
** Params:
**    char ***amb -> array of tables (made with ft_split - more info in libft)
**                   each index of the first array (amb[index1]) is a line
**                   (i.e. a different ambient lighting) of the file. At the
**                   second index (amb[index1][index2]) is a word (string) of
**                   the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_MEMORY] :: system could not allocate memory needed
*/

t_error	process_amb(char ***amb, t_scene *scene)
{
	char	**params;

	if (!amb)
	{
		scene->amb.ratio = 0.0;
		scene->amb.color = mx_vector(0, 0, 0);
	}
	else
	{
		if (!(params = ft_split(amb[0][2], ',')))
			return (NO_MEMORY);
		scene->amb.ratio = ft_atof(amb[0][1]);
		scene->amb.color = mx_vector(ft_atof(params[0]) / 255.0, \
									ft_atof(params[1]) / 255.0, \
									ft_atof(params[2]) / 255.0);
		ft_free_split(&params);
	}
	return (NO_ERROR);
}
