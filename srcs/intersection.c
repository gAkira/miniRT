/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:44:12 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/01 18:46:30 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	*intersection(void *obj, double t, t_mask mask)
{
	t_intersect	*intersect;

	if (!(intersect = (t_intersect*)malloc(sizeof(t_intersect))))
		return (NULL);
	intersect->obj = obj;
	intersect->t = t;
	intersect->mask = mask;
	return (intersect);
}

void		intersections(t_intersect ***list, t_intersect *intersect)
{
	int			len;
	int			put;
	t_intersect	**new_list;

	if ((list && !*list) || !intersect)
	{
		if (intersect && \
			(*list = (t_intersect**)ft_calloc(2, sizeof(t_intersect*))))
			(*list)[0] = intersect;
		return ;
	}
	len = 0;
	while (list && *list && (*list)[len])
		len++;
	put = 0;
	while (list && *list && (*list)[put] && intersect->t > (*list)[put]->t)
		put++;
	if (!(new_list = (t_intersect**)ft_calloc(len + 2, sizeof(t_intersect*))))
		return ;
	ft_memmove(new_list, *list, put * sizeof(t_intersect*));
	new_list[put] = intersect;
	ft_memmove(&(new_list[put + 1]), &((*list)[put]), \
									(len - put) * sizeof(t_intersect*));
	free(*list);
	*list = new_list;
}

t_intersect	*hit(t_intersect **list)
{
	int	i;

	if (!list)
		return (NULL);
	i = 0;
	while (list[i] && list[i]->t < 0.0 && !mx_equal(list[i]->t, 0.0))
		i++;
	return (list[i]);
}
