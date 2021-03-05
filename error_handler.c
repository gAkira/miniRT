/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:53:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/04 21:33:27 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*g_errormsgs[__ERRMAX] = {
	"No error",
	"Usage: ./miniRT <filename>.rt [--save]\nNot enough args.",
	"File provided is not a scene file: <filename>.rt",
	"File provided doesn't exist or you don't have permission to read it.",
};

void	error_handler(t_error error, t_args args)
{
	if (error)
	{
		errno = error;
		perror(g_errormsgs[error]);
		free_args(args);
		exit(error);
	}
}
