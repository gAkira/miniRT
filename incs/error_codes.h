/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:04:57 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 02:26:05 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# include <errno.h>

# define STDERR_FD 2

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
