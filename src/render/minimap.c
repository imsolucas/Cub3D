/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:22:57 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 15:12:35 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_border(t_game *game)
{
	int	border_x_start;
	int	border_y_start;
	int	border_x_end;
	int	border_y_end;
	int	x;
	int	y;

	border_x_start = 0;
	border_y_start = 0;
	border_x_end = game->map.width * MINIMAP_SCALE + 4;
	border_y_end = game->map.height * MINIMAP_SCALE + 4;
	y = border_y_start;
	while (y < border_y_end)
	{
		x = border_x_start;
		while (x < border_x_end)
		{
			if (x == border_x_start || x == border_x_end - 1
				|| y == border_y_start || y == border_y_end - 1)
				put_pixel(game, x, y, MINIMAP_BORDER_COLOR);
			else
				put_pixel(game, x, y, MINIMAP_BACKGROUND_COLOR);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	int map_x;
	int map_y;
	double ray_x;
	double ray_y;
	double ray_dir_x;
	double ray_dir_y;

	draw_minimap_border(game);
	draw_minimap_floor(game);
	draw_minimap_player(game);
	//init_minimap(game, mini);
	ray_x = game->player.x;
	ray_y = game->player.y;
	ray_dir_x = game->player.dir_x;
	ray_dir_y = game->player.dir_y;
	while (1)
	{
		map_x = (int)ray_x;
		map_y = (int)ray_y;
		if (map_x < 0 || map_y < 0 || map_x >= game->map.width
			|| map_y >= game->map.height || game->map.map[map_y][map_x] == '1')
			break ;
		draw_square(game, (int)((ray_x * MINIMAP_SCALE) + 2 - (MINIMAP_SCALE
					/ 10)), (int)((ray_y * MINIMAP_SCALE) + 2 - (MINIMAP_SCALE
					/ 10)), MINIMAP_SCALE / 5, 0xFF0000);
		ray_x += ray_dir_x * 0.1;
		ray_y += ray_dir_y * 0.1;
	}
}
