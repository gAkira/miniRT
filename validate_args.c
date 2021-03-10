/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:44:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 17:58:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_args(int argc, char **argv, t_args *args)
{
	char **fname;
	char **flag;

	if (!argv || !*argv)
		return ;
	fname = ft_split(argv[1], ' ');
	if (!fname || !*fname)
	{
		ft_free_split(&fname);
		return ;
	}
	args->filename = ft_strdup(fname[0]);
	ft_free_split(&fname);
	if (argc > 2)
	{
		flag = ft_split(argv[2], ' ');
		if (!flag || !*flag)
		{
			ft_free_split(&flag);
			return ;
		}
		if (!ft_strncmp(flag[0], "--save", ft_strlen("--save") + 1))
			args->save = true;
		ft_free_split(&flag);
	}
}

static bool	end_with_rt(char *filename)
{
	int		len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len > 3 && filename[len - 3] == '.' && \
		filename[len - 2] == 'r' && filename[len - 1] == 't')
		return (true);
	return (false);
}

static bool	file_exists(char *filename)
{
	int		fd;

	if (!filename)
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

t_error		validate_args(int argc, char **argv, t_args *args)
{
	ft_bzero(args, sizeof(t_args));
	if (!(argc - 1))
		return (NOT_ENOUGH_ARGS);
	get_args(argc, argv, args);
	allocate_flag(&(args->allocation), ARGS_FILENAME);
	if (!end_with_rt(args->filename))
		return (NOT_RT_FILE);
	if (!file_exists(args->filename))
		return (NO_FILE);
	return (0);
}
