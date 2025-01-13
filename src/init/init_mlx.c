/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:04:14 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/13 12:27:43 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *game)
{
	init_mlx(game);
	init_texture(game);
	// init_player(game);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
		error_exit("mlx_init failed");
	if (!game->map.width || !game->map.height)
	{
		printf("Error\nNo height and width provided\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->map.width,
			game->map.height, "cub3D");
	if (!game->win)
		error_exit("mlx_new_window failed");
	game->img = mlx_new_image(game->mlx, game->map.width, game->map.height);
		error_exit("mlx_new_image failed");
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		error_exit("mlx_get_data_addr failed");
}


