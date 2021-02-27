/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:43:00 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/25 17:54:55 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *size)
{
	int		lst_counter;
	t_list	*lst_it;

	lst_it = size;
	if (lst_it == 0)
		return (0);
	lst_counter = 1;
	while (lst_it->next != 0)
	{
		lst_counter++;
		lst_it = lst_it->next;
	}
	return (lst_counter);
}
