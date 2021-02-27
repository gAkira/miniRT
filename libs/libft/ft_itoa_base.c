/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:05:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/04 21:37:45 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lst_to_str(t_list *lst)
{
	int		i;
	int		length;
	t_list	*it;
	char	*str;

	it = lst;
	if (it == NULL)
		return (NULL);
	i = 0;
	length = ft_lstsize(it);
	str = (char*)ft_calloc(length + 1, sizeof(char));
	while (str != NULL && i < length)
	{
		str[i] = ((char*)(it->content))[0];
		it = it->next;
		i++;
	}
	ft_lstclear(&lst, &free);
	return (str);
}

char		*ft_itoa_base(int nbr, const char *base)
{
	int				sign;
	unsigned int	u_nbr;
	t_list			*num;
	t_list			*aux;

	num = NULL;
	if (ft_strlen(base) < 2)
		return (NULL);
	sign = (nbr < 0 ? -1 : 1);
	u_nbr = (nbr < 0 ? -nbr : nbr);
	if (u_nbr == 0)
		return (ft_substr(base, 0, 1));
	while (u_nbr > 0)
	{
		if (!(aux = ft_lstnew(ft_substr(base, u_nbr % ft_strlen(base), 1))))
		{
			ft_lstclear(&num, &free);
			return (NULL);
		}
		ft_lstadd_front(&num, aux);
		u_nbr /= ft_strlen(base);
	}
	if (sign < 0)
		ft_lstadd_front(&num, ft_lstnew(ft_strdup("-")));
	return (lst_to_str(num));
}
