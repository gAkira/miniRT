/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 22:03:17 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 20:55:21 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# include "typedefs.h"
# include <errno.h>

# define STDERR_FD 2

extern char		*g_errormsgs[__MAX_ERROR];

void	error_handler(t_error error, t_args args);

#endif
