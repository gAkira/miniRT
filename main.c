/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:48:45 by galves-d          #+#    #+#             */
/*   Updated: 2021/03/10 19:45:33 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_args	args;

	error_handler(validate_args(argc, argv, &args), &args);
	error_handler(validate_rt_file(&args), &args);
	printf("filename: %s\nsave: %d\n", args.filename, (int)args.save);
	free_args(&args);
	return (0);
}
