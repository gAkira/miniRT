/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:44:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/02/27 23:41:36 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_split(char ***s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (*s && (*s)[i])
		free((*s)[i++]);
	free(*s);
}

static bool	end_with_rt(char *argv)
{
	int		len;
	char	**filename;

	if (!argv)
		return (false);
	filename = ft_split(argv, ' ');
	if (!filename || !*filename)
	{
		free_split(&filename);
		return (false);
	}
	len = ft_strlen(filename[0]);
	if (len > 3 && filename[0][len - 3] == '.' && \
		filename[0][len - 2] == 'r' && filename[0][len - 1] == 't')
	{
		free_split(&filename);
		return (true);
	}
	free_split(&filename);
	return (false);
}

static bool	file_exists(char *argv)
{
	int		fd;
	char	**filename;

	filename = ft_split(argv, ' ');
	fd = open(filename[0], O_RDONLY);
	if (fd == -1)
	{
		free_split(&filename);
		return (false);
	}
	close(fd);
	free_split(&filename);
	return (true);
}

int			validate_args(int argc, char **argv)
{
	char	*file;

	file = argv[1];
	if (!(argc - 1))
		return (1);
	if (!end_with_rt(file))
		return (2);
	if (!file_exists(file))
		return (3);
	return (0);
}
