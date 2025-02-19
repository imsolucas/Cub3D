/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:50:21 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/19 16:01:50 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_pos(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.height)
		return (false);
	if (x < 0 || x >= (int)ft_strlen(game->map.map[y]))
		return (false);
	return (true);
}

static void	set_floor_color(t_game *game, t_mini *mini, int x, int y)
{
	if (game->map.map[y][x] == '1')
		mini->color = 0x333333;
	else if (game->map.map[y][x] == '0')
		mini->color = 0x666666;
	else if (game->map.map[y][x] == 'D')
		mini->color = 0x00FF00;
	else if (game->map.map[y][x] == 'C')
		mini->color = 0x006600;
}

void	draw_border_pixel(t_game *game, int x, int y, t_mini *mini)
{
	if (x == mini->border_x_start
		|| x == game->map.width * MINIMAP_SCALE + 3
		|| y == mini->border_y_start
		|| y == game->map.height * MINIMAP_SCALE + 3)
		put_pixel(game, x, y, MINIMAP_BORDER_COLOR);
	else
		put_pixel(game, x, y, MINIMAP_BACKGROUND_COLOR);
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
		while (++x < (int)ft_strlen(game->map.map[y]))
		{
			if (!is_valid_map_pos(game, x, y))
				continue ;
			mini.x = x * MINIMAP_SCALE + 2;
			mini.y = y * MINIMAP_SCALE + 2;
			mini.size = MINIMAP_SCALE;
			set_floor_color(game, &mini, x, y);
			draw_square(game, &mini);
		}
	}
}

void	draw_minimap_rays(t_game *game, t_mini *mini)
{
	int	map_x;
	int	map_y;

	while (1)
	{
		map_x = (int)mini->ray_x;
		map_y = (int)mini->ray_y;
		if (is_ray_blocked(game, mini, map_x, map_y))
			break ;
		mini->x = (int)((mini->ray_x * MINIMAP_SCALE) + 2
				- (MINIMAP_SCALE / 10));
		mini->y = (int)((mini->ray_y * MINIMAP_SCALE) + 2
				- (MINIMAP_SCALE / 10));
		mini->size = MINIMAP_SCALE / 5;
		mini->color = 0xFF0000;
		draw_square(game, mini);
		mini->ray_x += mini->ray_dir_x * 0.1;
		mini->ray_y += mini->ray_dir_y * 0.1;
	}
}
