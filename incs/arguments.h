/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:26:46 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 22:04:26 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include <stdbool.h>

# define VALID_IDENTIFIERS "#,R,A,c,l,pl,sp,sq,cy,tr"

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
