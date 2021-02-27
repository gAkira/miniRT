/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:03:33 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/26 00:16:03 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list		*lst_it;

	if (f == 0)
		return ;
	lst_it = lst;
	while (lst_it != 0)
	{
		(*f)(lst_it->content);
		lst_it = lst_it->next;
	}
}
