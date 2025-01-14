/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/14 11:02:01 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	init_struct(&game);
	if (!game.mlx)
		error_exit("mlx_init failed");
	parse(argv[1], &game);
	init_game(&game);
	mlx_hook(game.win, 17, 0, cleanup, &game);
	mlx_loop(game.mlx);
	return (0);
}
