/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:44:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 23:28:56 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "vec3.h"
# include "libft.h"
# include "error_codes.h"
# include "typedefs.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IDENTIFIERS "R,A,c,l,pl,sp,sq,cy,tr"

bool	in_range(int num, int min, int max);
bool	in_rangef(double num, double min, double max);
void	allocate_flag(size_t *alloc, size_t mask);
void	deallocate_flag(size_t *alloc, size_t maks);
bool	is_allocated_flag(size_t alloc, size_t mask);
t_error	validate_args(int argc, char **argv, t_args *args);
t_error	validate_rt_file(t_args *args);
t_error	validate_objs(t_args *args);
t_error	validate_res(char ***res);
t_error	validate_res_amb(char ***file);
void	free_args(t_args *args);

#endif
