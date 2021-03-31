/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:48:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/31 00:23:17 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Function name:
**    main
** Description:
**    Main function of the program
**    It must receive the path to a file (filename.rt) describing a scene and a
**    possible saving flag (--save)
**    Then it outputs the scene described in a window (or save it in bitmap
**    .bmp, depending on the flag)
** Params:
**    int argc -> number of arguments passed
**    char **argv -> table content with the parameters passed (array of strings)
** Return:
**    int -> return value when exiting of the program
**       [0] :: success!
**       other values :: some error occurred and it returns its respective value
*/

void	print_scene(t_scene scene);

int	main(int argc, char **argv)
{
	t_args	args;
	t_scene	scene;

	error_handler(validate_args(argc, argv, &args), &args, &scene);
	error_handler(validate_rt_file(&args), &args, &scene);
	error_handler(process_objs(&args, &scene), &args, &scene);
	//printf("filename: %s\nsave: %d\n", args.filename, (int)args.save);
	print_scene(scene);
	free_args(&args);
	free_scene(&scene);
	return (0);
}

void	print_scene(t_scene scene)
{
	int	i;

	printf("res:\n\tx: %ld\n\ty: %ld\n", scene.res.x, scene.res.y);
    printf("amb:\n\tratio: %f\n\tcolor: %f,%f,%f\n", scene.amb.ratio, \
        scene.amb.color.pos[0], scene.amb.color.pos[1], scene.amb.color.pos[2]);

	i = 0;
	while (scene.c && scene.c[i])
	{
		printf("camera[%d]:\n\tcoord: %f,%f,%f\n\tdir: %f,%f,%f\n\tfov: %ld\n", \
			i, \
			scene.c[i]->coord.pos[0], scene.c[i]->coord.pos[1], scene.c[i]->coord.pos[2], \
			scene.c[i]->dir.pos[0], scene.c[i]->dir.pos[1], scene.c[i]->dir.pos[2], \
			scene.c[i]->fov);
		i++;
	}

	i = 0;
	while (scene.l && scene.l[i])
	{
		printf("light[%d]:\n\tcoord: %f,%f,%f\n\tratio: %f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.l[i]->coord.pos[0], scene.l[i]->coord.pos[1], scene.l[i]->coord.pos[2], \
			scene.l[i]->ratio, \
			scene.l[i]->color.pos[0], scene.l[i]->color.pos[1], scene.l[i]->color.pos[2]);
		 i++;
	}

	i = 0;
	while (scene.pl && scene.pl[i])
	{
		printf("plane[%d]:\n\tcoord: %f,%f,%f\n\tdirection: %f,%f,%f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.pl[i]->coord.pos[0], scene.pl[i]->coord.pos[1], scene.pl[i]->coord.pos[2], \
			scene.pl[i]->dir.pos[0], scene.pl[i]->dir.pos[1], scene.pl[i]->dir.pos[2], \
			scene.pl[i]->color.pos[0], scene.pl[i]->color.pos[1], scene.pl[i]->color.pos[2]);
		i++;
	}

	i = 0;
	while (scene.sp && scene.sp[i])
	{
		printf("sphere[%d]:\n\tcoord: %f,%f,%f\n\tdiam: %f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.sp[i]->coord.pos[0], scene.sp[i]->coord.pos[1], scene.sp[i]->coord.pos[2], \
			scene.sp[i]->diam, \
			scene.sp[i]->color.pos[0], scene.sp[i]->color.pos[1], scene.sp[i]->color.pos[2]);
		i++;
	}

	i = 0;
	while (scene.sq && scene.sq[i])
	{
		printf("square[%d]:\n\tcoord: %f,%f,%f\n\tdirection: %f,%f,%f\n\tside: %f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.sq[i]->coord.pos[0], scene.sq[i]->coord.pos[1], scene.sq[i]->coord.pos[2], \
			scene.sq[i]->dir.pos[0], scene.sq[i]->dir.pos[1], scene.sq[i]->dir.pos[2], \
			scene.sq[i]->side, \
			scene.sq[i]->color.pos[0], scene.sq[i]->color.pos[1], scene.sq[i]->color.pos[2]);
		i++;
	}

	i = 0;
	while (scene.cy && scene.cy[i])
	{
		printf("cylinder[%d]:\n\tcoord: %f,%f,%f\n\tdirection: %f,%f,%f\n\tdiam: %f\n\theight: %f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.cy[i]->coord.pos[0], scene.cy[i]->coord.pos[1], scene.cy[i]->coord.pos[2], \
			scene.cy[i]->dir.pos[0], scene.cy[i]->dir.pos[1], scene.cy[i]->dir.pos[2], \
			scene.cy[i]->diam, scene.cy[i]->height, \
			scene.cy[i]->color.pos[0], scene.cy[i]->color.pos[1], scene.cy[i]->color.pos[2]);
		i++;
	}

	i = 0;
	while (scene.tr && scene.tr[i])
	{
		printf("triangle[%d]:\n\tcoord[0]: %f,%f,%f\n\tcoord[1]: %f,%f,%f\n\tcoord[2]: %f,%f,%f\n\tcolor: %f,%f,%f\n", \
			i, \
			scene.tr[i]->coord[0].pos[0], scene.tr[i]->coord[0].pos[1], scene.tr[i]->coord[0].pos[2], \
			scene.tr[i]->coord[1].pos[0], scene.tr[i]->coord[1].pos[1], scene.tr[i]->coord[1].pos[2], \
			scene.tr[i]->coord[2].pos[0], scene.tr[i]->coord[2].pos[1], scene.tr[i]->coord[2].pos[2], \
			scene.tr[i]->color.pos[0], scene.tr[i]->color.pos[1], scene.tr[i]->color.pos[2]);
		i++;
	}
}
