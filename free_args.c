/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:20:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/05 17:53:51 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_args(t_args args)
{
	int	i;

	free(args.filename);
	args.filename = NULL;
	if (args.file)
	{
		i = 0;
		while (args.file[i])
			ft_free_split(&args.file[i++]);
		free(args.file);
		args.file = NULL;
	}
}
