/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:53:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:17:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "error_handler.h"

/*
** Function name:
**    error_handler
** Description:
**    Receives a error value and take its decision
**       [NO_ERROR] :: nothing happens in the function and the program continues
**       other values :: show error message, free memory and finish program
** Params:
**    t_error error -> error value returned by some other function
**    t_args *args -> pointer to struct to free memory
** Return:
**    bool -> value of the bit asked in mask
**       [false] :: bit was 0
**       [true] :: bit was 1
*/

void	error_handler(t_error error, t_args *args, t_scene *scene)
{
	if (error)
	{
		errno = error;
		ft_putstr_fd("Error\n", STDERR_FD);
		ft_putstr_fd(g_errormsgs[error], STDERR_FD);
		ft_putstr_fd("\n", STDERR_FD);
		free_args(args);
		free_scene(scene);
		exit(error);
	}
}
