/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:28:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/19 14:41:24 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_game *game, t_mini *mini)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mini->size)
	{
		j = -1;
		while (++j < mini->size)
			put_pixel(game, mini->x + i, mini->y + j, mini->color);
	}
}

int	is_ray_blocked(t_game *game, t_mini *mini, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_y >= game->map.height ||
		map_x >= (int)ft_strlen(game->map.map[map_y]))
		return (1);

	if (game->map.map[map_y][map_x] == '1'
		|| game->map.map[map_y][map_x] == 'D')
		return (1);

	// Check left wall collision
	if (map_x > 0 && game->map.map[map_y][map_x - 1] == '1' 
		&& mini->ray_x - map_x < 0.1)
		return (1);

	// Check upper wall collision
	if (map_y > 0 && map_x < (int)ft_strlen(game->map.map[map_y - 1]) 
		&& game->map.map[map_y - 1][map_x] == '1' 
		&& mini->ray_y - map_y < 0.1)
		return (1);

	return (0);
}

void	init_minimap(t_game *game, t_mini *mini)
{
	mini->ray_x = game->player.x;
	mini->ray_y = game->player.y;
	mini->ray_dir_x = game->player.dir_x;
	mini->ray_dir_y = game->player.dir_y;
	mini->border_x_start = 0;
	mini->border_y_start = 0;
	mini->x = 0;
	mini->y = 0;
	mini->size = 0;
	mini->color = 0;
}
