/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:58:50 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 13:51:00 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message)
{
	ft_putendl_fd("Error\n", 2);
    ft_putendl_fd(message, 2);
	exit(1);
}

int	cleanup(t_game *game)
{
	if (game->north.img)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx, game->west.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	free_texture_path(game);
	free(game);
	exit(0);
	return (0);
}

void move_forward(t_game *game)
{
    double new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
    double new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
    
    if (game->map.map[(int)game->player.y][(int)new_x] != '1')
        game->player.x = new_x;
    if (game->map.map[(int)new_y][(int)game->player.x] != '1')
        game->player.y = new_y;
}

void move_backward(t_game *game)
{
	double new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
	double new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

void move_left(t_game *game)
{
	double new_x = game->player.x + game->player.dir_y * MOVE_SPEED;
	double new_y = game->player.y - game->player.dir_x * MOVE_SPEED;
	
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

void move_right(t_game *game)
{
	double new_x = game->player.x - game->player.dir_y * MOVE_SPEED;
	double new_y = game->player.y + game->player.dir_x * MOVE_SPEED;
	
	if (game->map.map[(int)game->player.y][(int)new_x] != '1')
		game->player.x = new_x;
	if (game->map.map[(int)new_y][(int)game->player.x] != '1')
		game->player.y = new_y;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		cleanup(game);
	else if (keycode == W)
		move_forward(game);
	else if (keycode == S)
		move_backward(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	return (0);
}
