/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/14 10:30:07 by abinti-a         ###   ########.fr       */
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
	parse(argv[1], &game);
	init_game(&game);
	mlx_loop(game.mlx);
	cleanup(&game);
	return (0);
}
