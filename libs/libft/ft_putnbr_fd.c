/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:05:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/24 23:42:50 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;
	char			r;

	if (n < 0)
		write(fd, "-", 1);
	if (n < 0)
		u_n = -n;
	else
		u_n = n;
	r = (u_n % 10) + '0';
	u_n /= 10;
	if (!u_n)
		write(fd, &r, 1);
	else
	{
		ft_putnbr_fd((int)u_n, fd);
		write(fd, &r, 1);
	}
}
