/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:03:17 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 22:45:22 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# include "typedefs.h"
# include <errno.h>

# define STDERR_FD 2

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

extern char		*g_errormsgs[__MAX_ERROR];

void	error_handler(t_error error, t_args *args);

#endif
