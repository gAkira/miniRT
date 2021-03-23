/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 02:59:18 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include <stdbool.h>

# define IDENTIFIERS "R,A,c,l,pl,sp,sq,cy,tr"

typedef enum	e_args_mask
{
	FILENAME_MASK,
	FILE_MASK,
	RES_MASK,
	AMB_MASK,
	C_MASK,
	L_MASK,
	PL_MASK,
	SP_MASK,
	SQ_MASK,
	CY_MASK,
	TR_MASK
}				t_args_mask;

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

#endif
