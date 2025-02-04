/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:28:59 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 16:33:12 by abinti-a         ###   ########.fr       */
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
