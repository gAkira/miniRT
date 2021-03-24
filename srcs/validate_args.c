/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:44:20 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 14:40:06 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** [STATIC] Function name:
**    get_args
** Description:
**    Parse the arguments passed in argv
**    Store the filename in args->filename
**    If there's a save flag (--save), then args->save = true; else it's false
** Params:
**    int argc -> number of arguments passed when calling the program
**    char **argv -> table of arguments passed when calling the program
**    t_args *args -> pointer to the struct to be filled
** Return:
**    ---
*/

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

/*
** [STATIC] Function name:
**    end_with_rt
** Description:
**    Verify if the filename obtained ends with .rt
** Params:
**    char *filename -> filename obtained
** Return:
**    bool -> report if the condition is satisfied
**       [false] :: filename does not end with .rt
**       [true] :: filename has the correct extension!
*/

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

/*
** [STATIC] Function name:
**    file_exists
** Description:
**    Verify if the given filename is from a file that exists or not
**    If it exists, also tells if you can read it
** Params:
**    char **filename -> filename to be tested
** Return:
**    bool -> report if the file exists and it is readable
**       [false] :: file doesn't exist and/or you don't have permission
**                  to read it
**       [true] :: everything is alright!
*/

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

/*
** Function name:
**    validate_args
** Description:
**    Fill args' attributes with zeroes/NULLs
**    Verify if there is enough arguments
**    Parse arguments in argv correctly, put it in args struct and set its flags
**    Verify if the given filename ends with .rt
**    Verify if the file exists (and if you have permission to read it)
** Params:
**    int argc -> number of arguments passed when calling the program
**    char **argv -> table of arguments passed when calling the program
**    t_args *args -> pointer to the struct to be filled
** Return:
**    t_error -> report the error found
**       [NO_ERROR] :: everything is alright
**       [NOT_ENOUGH_ARGS] :: not enough arguments
**       [NOT_RT_FILE] :: file doesn't end with .rt
**       [NO_FILE] :: file doesn't exist and/or you don't have permission
**                    to read it
*/

t_error		validate_args(int argc, char **argv, t_args *args)
{
	ft_bzero(args, sizeof(t_args));
	if (!(argc - 1))
		return (NOT_ENOUGH_ARGS);
	get_args(argc, argv, args);
	allocate_flag(&(args->allocation), FILENAME_MASK);
	if (!end_with_rt(args->filename))
		return (NOT_RT_FILE);
	if (!file_exists(args->filename))
		return (NO_FILE);
	return (0);
}
