/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 20:55:28 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <stdbool.h>

typedef struct	s_args
{
	char	*filename;
	bool	save;
	char	***file;
}				t_args;

typedef enum	e_error
{
	NO_ERROR,
	NOT_ENOUGH_ARGS,
	NOT_RT_FILE,
	NO_FILE,
	INVALID_IDENTIFIER,
	INVALID_QUANTITY_RES,
	INVALID_QUANTITY_AMB,
	__MAX_ERROR
}				t_error;

#endif
