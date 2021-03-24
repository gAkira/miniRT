/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rt_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:24:05 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 18:40:05 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    store_file_in_blocks
** Description:
**    Read the file (byte by byte) and stores it in a variable and transform
**    each tab '\t' in a space ' '
**    After that, it splits the file (line by line) with ft_split (see libft)
**    and free 'file_inline'
**    Then it splits each line of the stored file to get just the words without
**    any spacing, stores it in args->file and free 'file'
** Params:
**    int fd -> file descriptor of the file to read
**    t_args *args -> structure with the filename (args->filename) and an
**                    attribute (args->file) to store the file content
**                    in 'blocks'
** Return:
**    ---
*/

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
	ft_free_split(&file);
}

/*
** Function name:
**    validate_rt_file
** Description:
**    Verify if it's possible to open and read the specified file
**    Store content of the file in a array (each index represents a non-empty
**    line) and in each index there is a table with the line's content splitted
**    by the ft_split (see libft library for more information)
**    Also sets the correspondent allocation flag
** Params:
**    t_args *args -> structure with the filename (args->filename) and an
**                    attribute (args->file) to store the file content
**                    in 'blocks'
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NO_FILE] :: couldn't open and/or read the file
**       other values :: validate_objs will return the correspondent error code
*/

t_error		validate_rt_file(t_args *args)
{
	int		fd;
	t_error	error;

	if ((fd = open(args->filename, O_RDONLY)) < 0)
		return (NO_FILE);
	store_file_in_blocks(fd, args);
	allocate_flag(&(args->allocation), FILE_MASK);
	close(fd);
	error = NO_ERROR;
	if ((error = validate_objs(args)))
		return (error);
	return (error);
}
