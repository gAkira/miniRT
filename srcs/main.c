/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:48:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/24 00:08:28 by galves-d         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_args	args;
	t_scene	scene;

	error_handler(validate_args(argc, argv, &args), &args);
	error_handler(validate_rt_file(&args), &args);
	error_handler(process_objs(&args, &scene), &args);
	//printf("filename: %s\nsave: %d\n", args.filename, (int)args.save);
	printf("res:\n\tx: %ld\n\ty: %ld\n", scene.res.x, scene.res.y);
	printf("amb:\n\tratio: %f\n\tcolor: %d,%d,%d\n", scene.amb.ratio, \
				scene.amb.color.r, scene.amb.color.g, scene.amb.color.b);
	printf("camera:\n\tcoord: %f,%f,%f\n\torient: %f,%f,%f\n\tfov: %ld\n", \
				scene.c[0].coord.x, scene.c[0].coord.y, scene.c[0].coord.z, \
				scene.c[0].orient.x, scene.c[0].orient.y, scene.c[0].orient.z, \
				scene.c[0].fov);
	free(scene.c);
	free_args(&args);
	return (0);
}
