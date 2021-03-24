/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:48:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 23:00:05 by galves-d         ###   ########.fr       */
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
    printf("amb:\n\tratio: %f\n\tcolor: %d,%d,%d\n", scene.amb.ratio, \
        scene.amb.color.r, scene.amb.color.g, scene.amb.color.b);

	i = 0;
	while (scene.c && !scene.c[i].end)
	{
		printf("camera[%d]:\n\tcoord: %f,%f,%f\n\torient: %f,%f,%f\n\tfov: %ld\n", \
			i, \
			scene.c[i].coord.x, scene.c[i].coord.y, scene.c[i].coord.z, \
			scene.c[i].orient.x, scene.c[i].orient.y, scene.c[i].orient.z, \
			scene.c[i].fov);
		i++;
	}

	i = 0;
	while (scene.l && !scene.l[i].end)
	{
		printf("light[%d]:\n\tcoord: %f,%f,%f\n\tratio: %f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.l[i].coord.x, scene.l[i].coord.y, scene.l[i].coord.z, \
			scene.l[i].ratio, \
			scene.l[i].color.r, scene.l[i].color.g, scene.l[i].color.b);
		 i++;
	}

	i = 0;
	while (scene.pl && !scene.pl[i].end)
	{
		printf("plane[%d]:\n\tcoord: %f,%f,%f\n\torientation: %f,%f,%f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.pl[i].coord.x, scene.pl[i].coord.y, scene.pl[i].coord.z, \
			scene.pl[i].orient.x, scene.pl[i].orient.y, scene.pl[i].orient.z, \
			scene.pl[i].color.r, scene.pl[i].color.g, scene.pl[i].color.b);
		i++;
	}

	i = 0;
	while (scene.sp && !scene.sp[i].end)
	{
		printf("sphere[%d]:\n\tcoord: %f,%f,%f\n\tdiam: %f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.sp[i].coord.x, scene.sp[i].coord.y, scene.sp[i].coord.z, \
			scene.sp[i].diam, \
			scene.sp[i].color.r, scene.sp[i].color.g, scene.sp[i].color.b);
		i++;
	}

	i = 0;
	while (scene.sq && !scene.sq[i].end)
	{
		printf("square[%d]:\n\tcoord: %f,%f,%f\n\torientation: %f,%f,%f\n\tside: %f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.sq[i].coord.x, scene.sq[i].coord.y, scene.sq[i].coord.z, \
			scene.sq[i].orient.x, scene.sq[i].orient.y, scene.sq[i].orient.z, \
			scene.sq[i].side, \
			scene.sq[i].color.r, scene.sq[i].color.g, scene.sq[i].color.b);
		i++;
	}

	i = 0;
	while (scene.cy && !scene.cy[i].end)
	{
		printf("cylinder[%d]:\n\tcoord: %f,%f,%f\n\torientation: %f,%f,%f\n\tdiam: %f\n\theight: %f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.cy[i].coord.x, scene.cy[i].coord.y, scene.cy[i].coord.z, \
			scene.cy[i].orient.x, scene.cy[i].orient.y, scene.cy[i].orient.z, \
			scene.cy[i].diam, scene.cy[i].height, \
			scene.cy[i].color.r, scene.cy[i].color.g, scene.cy[i].color.b);
		i++;
	}

	i = 0;
	while (scene.tr && !scene.tr[i].end)
	{
		printf("triangle[%d]:\n\tcoord[0]: %f,%f,%f\n\tcoord[1]: %f,%f,%f\n\tcoord[2]: %f,%f,%f\n\tcolor: %d,%d,%d\n", \
			i, \
			scene.tr[i].coord[0].x, scene.tr[i].coord[0].y, scene.tr[i].coord[0].z, \
			scene.tr[i].coord[1].x, scene.tr[i].coord[1].y, scene.tr[i].coord[1].z, \
			scene.tr[i].coord[2].x, scene.tr[i].coord[2].y, scene.tr[i].coord[2].z, \
			scene.tr[i].color.r, scene.tr[i].color.g, scene.tr[i].color.b);
		i++;
	}
}
