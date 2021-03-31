/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:55 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/30 22:27:51 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    process_res
** Description:
**    Process each resolution (R) arguments and parameters
**    If there's no instance of res (R) in the scene file, it assumes:
**        x = 1080
**        y = 720
** Params:
**    char ***res -> array of tables (made with ft_split - more info in libft)
**                   each index of the first array (res[index1]) is a line
**                   (i.e. a different resolution) of the file. At the
**                   second index (res[index1][index2]) is a word (string) of
**                   the respective line
**    t_scene *scene -> reference to a scene instance. It contains attributes
**                      to store objs information
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
*/

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
