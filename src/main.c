/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/14 16:44:46 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		printf("Error\nMalloc failed\n");
		exit(1);
	}
	parse(argv[1], game);
	init_mlx(game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
