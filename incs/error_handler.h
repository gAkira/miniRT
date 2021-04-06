/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:03:17 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/06 23:02:09 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include "error_codes.h"

/*
** Define usages for each error
*/

# define USAGE_ARGS_0 "\nUsage: ./miniRT <filename.rt> [--save]"

# define USAGE_RES_0 "\nUsage: R <X-resolution> <Y-resolution>"
# define USAGE_RES_1 "\nUsage: R <X-resolution> <Y-resolution>"
# define USAGE_RES_2 "\nUsage: R <1:INT_MAX> <1:INT_MAX>"

# define USAGE_AMB_0 "\nUsage: A <amb. light. ratio> <RGB color>"
# define USAGE_AMB_1 "\nUsage: A <amb. light. ratio> <R,G,B>"
# define USAGE_AMB_2 "\nUsage: A <0.0:1.0> <0:255,_,_>"

# define USAGE_C_0 "\nUsage: c <XYZ coords.> <XYZ orientation> <Field Of View>"
# define USAGE_C_1 "\nUsage: c <X,Y,Z> <X,Y,Z> <FOV>"
# define USAGE_C_2 "\nUsage: c <LimInf:LimSup,_,_> <-1.0:1.0,_,_> <0.0:180.0>"

# define USAGE_L_0 "\nUsage: l <XYZ coords.> <Light brightness> <RGB color>"
# define USAGE_L_1 "\nUsage: l <X,Y,Z> <Brightness ratio> <R,G,B>"
# define USAGE_L_2 "\nUsage: l <LimInf:LimSup,_,_> <0.0:1.0> <0:255,_,_>"

# define USAGE_SP_0 "\nUsage: sp <XYZ coords.> <Sphere diameter> <RGB color>"
# define USAGE_SP_1 "\nUsage: sp <X,Y,Z> <Sphere diameter> <R,G,B>"
# define USAGE_SP_2 "\nUsage: sp <LimInf:LimSup,_,_> <0.0:LimSup> <0:255,_,_>"

# define USAGE_PL_0 "\nUsage: pl <XYZ coords.> <XYZ orientation> <RGB color>"
# define USAGE_PL_1 "\nUsage: pl <X,Y,Z> <X,Y,Z> <R,G,B>"
# define USAGE_PL_2 "\nUsage: pl <LimInf:LimSup,_,_> <-1.0:1.0,_,_> <0:255,_,_>"

# define USAGE_SQ_0_0 "\nUsage: sq <XYZ coord.> <XYZ orientation>"
# define USAGE_SQ_0_1 " <Side size> <RGB color>"
# define USAGE_SQ_1 "\nUsage: sq <X,Y,Z> <X,Y,Z> <Size> <R,G,B>"
# define USAGE_SQ_2_0 "\nUsage: sq <LimInf:LimSup,_,_> <-1.0:1.0,_,_>"
# define USAGE_SQ_2_1 " <0.0:LimSup> <0:255,_,_>"

# define USAGE_CY_0_0 "\nUsage: cy <XYZ coord.> <XYZ orientation>"
# define USAGE_CY_0_1 " <Diameter> <Height> <RGB color>"
# define USAGE_CY_1 "\nUsage: cy <X,Y,Z> <X,Y,Z> <Diameter> <Height> <R,G,B>"
# define USAGE_CY_2_0 "\nUsage: cy <LimInf:LimSup,_,_> <-1.0:1.0,_,_>"
# define USAGE_CY_2_1 " <0.0:LimSup> <0.0:LimSup> <0:255,_,_>"

# define USAGE_TR_0_0 "\nUsage: tr <1st XYZ coord.> <2nd XYZ coord.>"
# define USAGE_TR_0_1 " <3rd XYZ coord.> <RGB color>"
# define USAGE_TR_1 "\nUsage: tr <X,Y,Z> <X,Y,Z> <X,Y,Z> <R,G,B>"
# define USAGE_TR_2_0 "\nUsage: tr <LimInf:LimSup,_,_> <LimInf:LimSup,_,_>"
# define USAGE_TR_2_1 " <LimInf:LimSup,_,_> <0:255,_,_>"

/*
** Error messages associated to its respective value of error.
** For more information, see the declaration of t_error.
*/

static char		*g_errormsgs[__MAX_ERROR] = {
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

	"System ran out of memory and had trouble while allocating memory.",
	"An error occurred while setting up minilibx server.",

	"OK",
};

#endif
