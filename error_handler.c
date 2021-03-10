/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:53:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 19:46:01 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*g_errormsgs[__MAX_ERROR] = {
	"No error",
	"Usage: ./miniRT <filename>.rt [--save]\nNot enough args.",
	"File provided is not a scene file: <filename>.rt",
	"File provided doesn't exist or you don't have permission to read it.",
	"There is an invalid identifier in the scene file.",
	"There is more than one instance of the resolution (R).",
	"There is more than one instance of the ambient lightning (A).",
	"Wrong number of arguments in resolution (R).",
	"Wrong number of arguments in ambient lightning (A).",
};

void	error_handler(t_error error, t_args *args)
{
	if (error)
	{
		errno = error;
		ft_putstr_fd("Error\n", STDERR_FD);
		ft_putstr_fd(g_errormsgs[error], STDERR_FD);
		ft_putstr_fd("\n", STDERR_FD);
		free_args(args);
		exit(error);
	}
}
