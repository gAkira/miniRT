/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/12 22:29:10 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

# include <stdbool.h>

# define ARGS_FILENAME	0
# define ARGS_FILE		1
# define ARGS_RES		2
# define ARGS_AMB		3
# define ARGS_C			4
# define ARGS_L			5
# define ARGS_PL		6
# define ARGS_SP		7
# define ARGS_SQ		8
# define ARGS_CY		9
# define ARGS_TR		10

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
	WRONG_NUM_ARGS_RES,
	BAD_FORMAT_RES,
	WRONG_ARGS_RANGE_RES,

	INVALID_QUANTITY_AMB,
	WRONG_NUM_ARGS_AMB,
	BAD_FORMAT_AMB,
	WRONG_ARGS_RANGE_AMB,

	WRONG_NUM_ARGS_C,
	BAD_FORMAT_C,
	WRONG_ARGS_RANGE_C,

	WRONG_NUM_ARGS_L,
	BAD_FORMAT_L,
	WRONG_ARGS_RANGE_L,

	WRONG_NUM_ARGS_SP,
	BAD_FORMAT_SP,
	WRONG_ARGS_RANGE_SP,

	WRONG_NUM_ARGS_PL,
	BAD_FORMAT_PL,
	WRONG_ARGS_RANGE_PL,

	WRONG_NUM_ARGS_SQ,
	BAD_FORMAT_SQ,
	WRONG_ARGS_RANGE_SQ,

	WRONG_NUM_ARGS_CY,
	BAD_FORMAT_CY,
	WRONG_ARGS_RANGE_CY,

	WRONG_NUM_ARGS_TR,
	BAD_FORMAT_TR,
	WRONG_ARGS_RANGE_TR,

	__MAX_ERROR
}				t_error;

#endif
