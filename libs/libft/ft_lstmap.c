/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:18:44 by galves-d          #+#    #+#             */
/*   Updated: 2020/01/26 00:55:31 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list		*new_lst;

	if (lst == 0)
		return (0);
	new_lst = ft_lstnew((*f)(lst->content));
	if (new_lst == 0)
	{
		ft_lstclear(&new_lst, del);
		return (0);
	}
	new_lst->next = ft_lstmap(lst->next, f, del);
	return (new_lst);
}
