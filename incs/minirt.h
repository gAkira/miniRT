/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:44:06 by galves-d          #+#    #+#             */
/*   Updated: 2021/04/08 23:55:20 by galves-d         ###   ########.fr       */
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
# include "mlx_server.h"
# include "mathx.h"
# include "libft.h"
# include "error_codes.h"
# include "arguments.h"
# include "mask.h"
# include "scene.h"
# include "render.h"

/*
** Auxiliary functions
*/

bool		in_range(int num, int min, int max);
bool		in_rangef(double num, double min, double max);
bool		is_numerical(char *str);
bool		are_numerical(char **tab);
void		allocate_flag(size_t *alloc, size_t mask);
void		deallocate_flag(size_t *alloc, size_t maks);
bool		is_allocated_flag(size_t alloc, size_t mask);
t_tuple		hadamard(t_tuple color1, t_tuple color2);
t_material	material(void);

/*
** Validation
*/

t_error		validate_args(int argc, char **argv, t_args *args);
t_error		validate_rt_file(t_args *args);
t_error		validate_objs(t_args *args);
t_error		validate_res(char ***res);
t_error		validate_amb(char ***amb);
t_error		validate_c(char ***c);
t_error		validate_l(char ***l);
t_error		validate_pl(char ***pl);
t_error		validate_sp(char ***sp);
t_error		validate_sq(char ***sq);
t_error		validate_cy(char ***cy);
t_error		validate_tr(char ***tr);

/*
** Process objects in scene file
*/

t_error		process_scene(t_args *args, t_scene *scene);
t_error		process_res(char ***res, t_scene *scene);
t_error		process_amb(char ***amb, t_scene *scene);
t_error		process_c(char ***c, t_scene *scene);
t_error		process_l(char ***l, t_scene *scene);
t_error		process_pl(char ***pl, t_scene *scene);
t_error		process_sp(char ***sp, t_scene *scene);
t_error		process_sq(char ***sq, t_scene *scene);
t_error		process_cy(char ***cy, t_scene *scene);
t_error		process_tr(char ***tr, t_scene *scene);

/*
** Canvas functions
*/

t_canvas	*create_canvas(size_t x, size_t y);
void		free_canvas(t_canvas *canvas);
void		write_canvas(t_canvas *canvas, size_t x, size_t y, int color);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

/*
** Ray functions
*/

t_ray		ray(t_tuple origin, t_tuple direction);
t_tuple		ray_pos(t_ray r, double t);
t_ray		ray_transform(t_matrix m, t_ray r);
t_tuple		reflect(t_tuple in, t_tuple normal);
t_ray		ray_for_pixel(t_c *c, size_t px, size_t py);

/*
** Intersection functions
*/

t_intersect	*intersection(void *obj, double t, t_mask mask);
void		intersections(t_intersect ***list, t_intersect *intersect);
t_intersect	*hit(t_intersect **list);
void		free_intersections(t_intersect **list);
t_intersect	**intersect_scene(t_scene *scene, t_ray ray);
void		intersect_sp(t_intersect ***list, t_sp *sp, t_ray ray);
void		get_intersects_sp(t_intersect ***list, t_sp **sp, t_ray ray);
t_tuple		normal_at(void *obj, t_tuple world_point, t_mask mask);
t_tuple		normal_sp(t_sp *sp, t_tuple world_point);


/*
** Get color
*/

t_comps		prepare_comps(t_intersect *intersect, t_ray ray);
t_tuple		lighting(t_material mat, t_l *l, t_comps comps);
t_tuple		shade_hit(t_scene *scene, t_comps comps);

/*
** Free memory
*/

void		free_args(t_args *args);
void		free_scene(t_scene *scene);

/*
** Error handling
*/

void		error_handler(t_error error, t_args *args, t_scene *scene);

/*
** Mlx config
*/

t_error		setup_mlx(t_scene *scene, t_mlx *server);
int			close_mlx(t_mlx *server);

#endif
