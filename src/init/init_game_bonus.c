/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:43:20 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/13 14:46:34 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_door(t_game *game);

void	init_game(t_game *game)
{
	init_mlx(game);
	init_texture(game);
	init_door(game);
	init_player(game);
}

void	init_door(t_game *game)
{
	int	tmp_bpp;
	int	tmp_line_len;
	int	tmp_endian;

	game->door_open.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/eagle.xpm", &game->door_open.width,
			&game->door_open.height);
	if (!game->door_open.img)
		error_exit("Failed to load door_open texture");
	game->door_close.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/door.xpm", &game->door_close.width,
			&game->door_close.height);
	if (!game->door_close.img)
		error_exit("Failed to load door_close texture");
	game->door_open.addr = mlx_get_data_addr(game->door_open.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->door_open.addr)
		error_exit("Failed to get door_open texture address");
	game->door_close.addr = mlx_get_data_addr(game->door_close.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->door_close.addr)
		error_exit("Failed to get door_close texture address");
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
