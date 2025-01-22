/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:04:14 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 07:33:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *game)
{
	init_mlx(game);
	init_texture(game);
	//init_player(game);
}

void	init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        error_exit("mlx_init failed");
    }
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
    if (!game->win)
		error_exit("mlx_new_window failed");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		error_exit("mlx_new_image failed");
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		error_exit("mlx_get_data_addr failed");
}
