/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:53:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 22:30:34 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char			*g_errormsgs[__MAX_ERROR] = {
	"No error.",
	"Not enough arguments!" USAGE_ARGS_0,
	"File provided is not a scene file: <filename.rt>",
	"File provided doesn't exist or you don't have permission to read.",

	"There is an invalid identifier in the scene file.",

	"There is more than one instance of the resolution (R).",
	"Wrong number of arguments in resolution (R)." USAGE_RES_0,
	"Bad format of arguments in resolution (R)." USAGE_RES_1,
	"Wrong argument range in resolution (R)." USAGE_RES_2,

	"There is more than one instance of the ambient lightning (A).",
	"Wrong number of arguments in ambient lightning (A)." USAGE_AMB_0,
	"Bad format of arguments in ambient lightning (A)." USAGE_AMB_1,
	"Wrong argument range in ambient lightning (A)." USAGE_AMB_2,

	"Wrong number of arguments in camera (c)." USAGE_C_0,
	"Bad format of arguments in camera (c)." USAGE_C_1,
	"Wrong argument range in camera (c)." USAGE_C_2,

	"Wrong number of arguments in light (l)." USAGE_L_0,
	"Bad format of arguments in light (l)." USAGE_L_1,
	"Wrong argument range in light (l)." USAGE_L_2,

	"Wrong number of arguments in sphere (sp)." USAGE_SP_0,
	"Bad format of arguments in sphere (sp)." USAGE_SP_1,
	"Wrong argument range in sphere (sp)." USAGE_SP_2,

	"Wrong number of arguments in plane (pl)." USAGE_PL_0,
	"Bad format of arguments in plane (pl)." USAGE_PL_1,
	"Wrong argument range in plane (pl)." USAGE_PL_2,

	"Wrong number of arguments in square (sq)." USAGE_SQ_0_0 USAGE_SQ_0_1,
	"Bad format of arguments in square (sq)." USAGE_SQ_1,
	"Wrong argument range in square (sq)." USAGE_SQ_2_0 USAGE_SQ_2_1,

	"Wrong number of arguments in cylinder (cy)." USAGE_CY_0_0 USAGE_CY_0_1,
	"Bad format of arguments in cylinder (cy)." USAGE_CY_1,
	"Wrong argument range in cylinder (cy)." USAGE_CY_2_0 USAGE_CY_2_1,

	"Wrong number of arguments in triangle (tr)." USAGE_TR_0_0 USAGE_TR_0_1,
	"Bad format of arguments in triangle (tr)." USAGE_TR_1,
	"Wrong argument range in triangle (tr)." USAGE_TR_2_0 USAGE_TR_2_1,
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
