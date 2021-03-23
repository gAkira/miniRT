/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rt_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:24:05 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 02:42:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_argsfile(t_args *args)
{
	int	line_len;
	int	block_len;

	line_len = 0;
	while (args->file[line_len])
	{
		printf("args->file[%d]:\n", line_len);
		block_len = 0;
		while (args->file[line_len][block_len])
		{
			printf("   args->file[%d][%d] = %s\n", line_len, block_len, \
					args->file[line_len][block_len]);
			block_len++;
		}
		line_len++;
	}
}

static void	store_file_in_blocks(int fd, t_args *args)
{
	int		i;
	char	*file_inline;
	char	**file;

	i = 0;
	file_inline = NULL;
	while (read(fd, \
		&(file_inline = (char*)ft_realloc(file_inline, i, i + 1))[i], 1) > 0)
		i++;
	file_inline[i] = '\0';
	i = 0;
	while (file_inline[i])
		if (file_inline[i++] == '\t')
			file_inline[i - 1] = ' ';
	file = ft_split(file_inline, '\n');
	free(file_inline);
	i = 0;
	while (file[i])
		i++;
	args->file = (char***)ft_calloc(i + 1, sizeof(char**));
	i = 0;
	while (file[i++])
		args->file[i - 1] = ft_split(file[i - 1], ' ');
	print_argsfile(args);
	ft_free_split(&file);
}

t_error		validate_rt_file(t_args *args)
{
	int		fd;
	t_error	error;

	if ((fd = open(args->filename, O_RDONLY)) < 0)
		return (NO_FILE);
	store_file_in_blocks(fd, args);
	allocate_flag(&(args->allocation), FILE_MASK);
	close(fd);
	if ((error = validate_objs(args)))
		return (error);
	return (error);
}
