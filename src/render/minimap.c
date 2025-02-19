/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:22:57 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/19 15:57:38 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_player(t_game *game)
{
	t_mini	mini;

	mini.size = MINIMAP_SCALE;
	mini.x = (int)((game->player.x * MINIMAP_SCALE) + 2 - (mini.size / 2));
	mini.y = (int)((game->player.y * MINIMAP_SCALE) + 2 - (mini.size / 2));
	mini.color = 0xFFFF00;
	draw_square(game, &mini);
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
			draw_border_pixel(game, x, y, mini);
	}
}

void	draw_minimap(t_game *game)
{
	t_mini	mini;

	init_minimap(game, &mini);
	draw_minimap_border(game, &mini);
	draw_minimap_floor(game);
	draw_minimap_player(game);
	draw_minimap_rays(game, &mini);
}
