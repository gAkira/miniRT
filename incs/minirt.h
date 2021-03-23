/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:44:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/23 23:41:08 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "vec3.h"
# include "libft.h"
# include "error_codes.h"
# include "arguments.h"
# include "scene.h"

/*
** Auxiliary functions
*/

bool	in_range(int num, int min, int max);
bool	in_rangef(double num, double min, double max);
void	allocate_flag(size_t *alloc, size_t mask);
void	deallocate_flag(size_t *alloc, size_t maks);
bool	is_allocated_flag(size_t alloc, size_t mask);

/*
** Validation
*/

t_error	validate_args(int argc, char **argv, t_args *args);
t_error	validate_rt_file(t_args *args);
t_error	validate_objs(t_args *args);
t_error	validate_res(char ***res);
t_error	validate_amb(char ***amb);
t_error	validate_c(char ***c);
t_error	validate_l(char ***l);
t_error	validate_pl(char ***pl);
t_error	validate_sp(char ***sp);
t_error	validate_sq(char ***sq);
t_error	validate_cy(char ***cy);
t_error	validate_tr(char ***tr);

/*
** Process objects in scene file
*/

t_error	process_objs(t_args *args, t_scene *scene);
t_error process_res(char ***res, t_scene *scene);
t_error process_amb(char ***amb, t_scene *scene);
t_error process_c(char ***c, t_scene *scene);
//t_error process_l(char ***l, t_scene *scene);
//t_error process_pl(char ***pl, t_scene *scene);
//t_error process_sp(char ***sp, t_scene *scene);
//t_error process_sq(char ***sq, t_scene *scene);
//t_error process_cy(char ***cy, t_scene *scene);
//t_error process_tr(char ***tr, t_scene *scene);

/*
** Free memory
*/

void	free_args(t_args *args);

/*
** Error handling
*/

void	error_handler(t_error error, t_args *args);

#endif