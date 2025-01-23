/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:27 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 16:06:14 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_game *game)
{
	while (game->frame_delay++ == FRAME_DELAY)
	{
		move_player(game);
		render_frame(game);
		game->frame_delay = 0;
	}
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		cleanup(game);
	else if (keycode == W)
		game->player.move_forward = true;
	else if (keycode == S)
		game->player.move_backward = true;
	else if (keycode == A)
		game->player.move_left = true;
	else if (keycode == D)
		game->player.move_right = true;
	else if (keycode == LEFT)
		game->player.rotate_left = true;
	else if (keycode == RIGHT)
		game->player.rotate_right = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == ESC)
		cleanup(game);
	else if (keycode == W)
		game->player.move_forward = false;
	else if (keycode == S)
		game->player.move_backward = false;
	else if (keycode == A)
		game->player.move_left = false;
	else if (keycode == D)
		game->player.move_right = false;
	else if (keycode == LEFT)
		game->player.rotate_left = false;
	else if (keycode == RIGHT)
		game->player.rotate_right = false;
	return (0);
}

void	move_player(t_game *game)
{
	if (game->player.move_forward)
		move_forward(game);
	if (game->player.move_backward)
		move_backward(game);
	if (game->player.move_left)
		move_left(game);
	if (game->player.move_right)
		move_right(game);
	if (game->player.rotate_left)
		rotate_left(game);
	if (game->player.rotate_right)
		rotate_right(game);
}
