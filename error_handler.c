/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:53:48 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/27 22:22:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_handler(int error_num)
{
	if (error_num)
	{
		printf("Errrrrooouuuuu!\nNo.: %d\n", error_num);
		exit(error_num);
	}
}
