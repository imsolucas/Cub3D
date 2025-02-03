/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:28:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:27 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			put_pixel(game, x + i, y + j, color);
		}
	}
}

void init_bresenham(t_mini *mini)
{
	mini->dx = abs(mini->x1 - mini->x0);
	mini->dy = abs(mini->y1 - mini->y0);
	if (mini->x0 < mini->x1)
		mini->sx = 1;
	else
		mini->sx = -1;
	if (mini->y0 < mini->y1)
		mini->sy = 1;
	else
		mini->sy = -1;
	mini->err = mini->dx - mini->dy;
}

void	draw_line_minimap(t_game *game, t_mini *mini, int color)
{
	init_bresenham(mini);
	while (1)
	{
		put_pixel(game, mini->x0, mini->y0, color);
		if (mini->x0 == mini->x1 && mini->y0 == mini->y1)
			break ;
		mini->e2 = 2 * mini->err;
		if (mini->e2 > -mini->dy)
		{
			mini->err -= mini->dy;
			mini->x0 += mini->sx;
		}
		if (mini->e2 < mini->dx)
		{
			mini->err += mini->dx;
			mini->y0 += mini->sy;
		}
	}
}

void draw_minimap_floor(t_game *game)
{
    int x;
    int y;

    y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
				draw_square(game, x * MINIMAP_SCALE + 2, y * MINIMAP_SCALE + 2,
					MINIMAP_SCALE, 0x333333);
			else if (game->map.map[y][x] == '0')
				draw_square(game, x * MINIMAP_SCALE + 2, y * MINIMAP_SCALE + 2,
					MINIMAP_SCALE, 0x666666);
		}
	}
}

void init_minimap(t_game *game, t_mini *mini)
{
    mini->ray_x = game->player.x;
    mini->ray_y = game->player.y;
    mini->ray_dir_x = game->player.dir_x;
    mini->ray_dir_y = game->player.dir_y;
}

void draw_minimap_player(t_game *game)
{
    int player_square_size;
    int player_draw_x;
    int player_draw_y;

    player_square_size = MINIMAP_SCALE;
    player_draw_x = (int)((game->player.x * MINIMAP_SCALE) + 2
            - (player_square_size / 2));
    player_draw_y = (int)((game->player.y * MINIMAP_SCALE) + 2
            - (player_square_size / 2));
    draw_square(game, player_draw_x, player_draw_y, player_square_size,
        0xFFFF00);
}
