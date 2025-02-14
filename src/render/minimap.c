/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:22:57 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/14 11:15:28 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_game *game)
{
	int		map_x;
	int		map_y;
	t_mini	mini;

	init_minimap(game, &mini);
	draw_minimap_border(game, &mini);
	draw_minimap_floor(game);
	draw_minimap_player(game);
	while (1)
	{
		map_x = (int)mini.ray_x;
		map_y = (int)mini.ray_y;
		if (is_ray_blocked(game, &mini, map_x, map_y))
			break ;
		mini.x = (int)((mini.ray_x * MINIMAP_SCALE) + 2 - (MINIMAP_SCALE / 10));
		mini.y = (int)((mini.ray_y * MINIMAP_SCALE) + 2 - (MINIMAP_SCALE / 10));
		mini.size = MINIMAP_SCALE / 5;
		mini.color = 0xFF0000;
		draw_square(game, &mini);
		mini.ray_x += mini.ray_dir_x * 0.1;
		mini.ray_y += mini.ray_dir_y * 0.1;
	}
}

void	draw_minimap_border(t_game *game, t_mini *mini)
{
	int	border_x_end;
	int	border_y_end;
	int	x;
	int	y;

	border_x_end = game->map.width * MINIMAP_SCALE + 4;
	border_y_end = game->map.height * MINIMAP_SCALE + 4;
	y = mini->border_y_start - 1;
	while (++y < border_y_end)
	{
		x = mini->border_x_start - 1;
		while (++x < border_x_end)
		{
			if (x == mini->border_x_start || x == border_x_end - 1
				|| y == mini->border_y_start || y == border_y_end - 1)
				put_pixel(game, x, y, MINIMAP_BORDER_COLOR);
			else
				put_pixel(game, x, y, MINIMAP_BACKGROUND_COLOR);
		}
	}
}

void	draw_minimap_floor(t_game *game)
{
	int		x;
	int		y;
	t_mini	mini;

	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			mini.x = x * MINIMAP_SCALE + 2;
			mini.y = y * MINIMAP_SCALE + 2;
			mini.size = MINIMAP_SCALE;
			if (game->map.map[y][x] == '1')
				mini.color = 0x333333;
			else if (game->map.map[y][x] == '0')
				mini.color = 0x666666;
			else if (game->map.map[y][x] == 'D')
				mini.color = 0x00FF00;
			else if (game->map.map[y][x] == 'C')
				mini.color = 0x006600;
			draw_square(game, &mini);
		}
	}
}

void	draw_minimap_player(t_game *game)
{
	t_mini	mini;

	mini.size = MINIMAP_SCALE;
	mini.x = (int)((game->player.x * MINIMAP_SCALE) + 2 - (mini.size / 2));
	mini.y = (int)((game->player.y * MINIMAP_SCALE) + 2 - (mini.size / 2));
	mini.color = 0xFFFF00;
	draw_square(game, &mini);
}
