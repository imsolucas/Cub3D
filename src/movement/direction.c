/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:42:52 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 16:04:19 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_x * MOVE_SPEED;
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_x * MOVE_SPEED;
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}
