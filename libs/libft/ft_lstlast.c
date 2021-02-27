/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:58:00 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/25 18:05:12 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list		*lst_it;

	if (lst == 0)
		return (lst);
	lst_it = lst;
	while (lst_it->next != 0)
		lst_it = lst_it->next;
	return (lst_it);
}
