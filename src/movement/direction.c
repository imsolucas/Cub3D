/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:42:52 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/13 09:57:37 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = MOVE_SPEED;
	if (game->player.sprint)
		speed = SPRINT_SPEED;
	new_x = game->player.x + game->player.dir_x * speed;
	new_y = game->player.y + game->player.dir_y * speed;
	if (can_move(game, (int)game->player.y, (int)new_x))
		game->player.x = new_x;
	if (can_move(game, (int)new_y, (int)game->player.x))
		game->player.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = MOVE_SPEED;
	if (game->player.sprint)
		speed = SPRINT_SPEED;
	new_x = game->player.x - game->player.dir_x * speed;
	new_y = game->player.y - game->player.dir_y * speed;
	if (can_move(game, (int)game->player.y, (int)new_x))
		game->player.x = new_x;
	if (can_move(game, (int)new_y, (int)game->player.x))
		game->player.y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = MOVE_SPEED;
	if (game->player.sprint)
		speed = SPRINT_SPEED;
	new_x = game->player.x + game->player.dir_y * speed;
	new_y = game->player.y - game->player.dir_x * speed;
	if (can_move(game, (int)game->player.y, (int)new_x))
		game->player.x = new_x;
	if (can_move(game, (int)new_y, (int)game->player.x))
		game->player.y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = MOVE_SPEED;
	if (game->player.sprint)
		speed = SPRINT_SPEED;
	new_x = game->player.x - game->player.dir_y * speed;
	new_y = game->player.y + game->player.dir_x * speed;
	if (can_move(game, (int)game->player.y, (int)new_x))
		game->player.x = new_x;
	if (can_move(game, (int)new_y, (int)game->player.x))
		game->player.y = new_y;
}

int	can_move(t_game *game, int y, int x)
{
	int	i;

	if (game->map.map[y][x] == '1')
		return (0);
	if (game->map.map[y][x] == 'D')
	{
		i = -1;
		while (++i < game->map.door_count)
		{
			if (game->map.doors[i].x == x && game->map.doors[i].y == y)
				return (game->map.doors[i].is_open);
		}
		return (0);
	}
	return (1);
}
