/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 17:54:33 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <stdbool.h>

# define ARGS_FILENAME	(1 << 0)
# define ARGS_FILE		(1 << 1)
# define ARGS_RES		(1 << 2)
# define ARGS_AMB		(1 << 3)
# define ARGS_C			(1 << 4)
# define ARGS_L			(1 << 5)
# define ARGS_PL		(1 << 6)
# define ARGS_SP		(1 << 7)
# define ARGS_SQ		(1 << 8)
# define ARGS_CY		(1 << 9)
# define ARGS_TR		(1 << 10)

typedef struct	s_args
{
	size_t	allocation;

	char	*filename;
	bool	save;
	char	***file;

	char	***res;
	char	***amb;
	char	***c;
	char	***l;
	char	***pl;
	char	***sp;
	char	***sq;
	char	***cy;
	char	***tr;
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
	WRONG_NUM_ARGS_RES,
	WRONG_NUM_ARGS_AMB,
	__MAX_ERROR
}				t_error;

#endif
