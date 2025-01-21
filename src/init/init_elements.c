/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:24:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/21 11:02:01 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
	int tmp_bpp;
	int tmp_line_len;
	int tmp_endian;

	game->north.img = mlx_xpm_file_to_image(game->mlx, game->north.path,
			&game->north.width, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->north.img || !game->north.addr)
		error_exit("Failed to load North texture");
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->south.path,
			&game->south.width, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->south.img || !game->south.addr)
		error_exit("Failed to load South texture");
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->east.path,
			&game->east.width, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img, &tmp_bpp,&tmp_line_len,
			&tmp_endian);
	if (!game->east.img || !game->east.addr)
		error_exit("Failed to load East texture");
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->west.path,
			&game->west.width, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img, &tmp_bpp,&tmp_line_len, &tmp_endian);
	if (!game->west.img || !game->west.addr)
		error_exit("Failed to load West texture");
}

/**
 * Angle (in radians) converted to direction vector the player is facing:
 *
 * - North (facing upwards):
 * 		angle = π/2
 * 		(cos(π/2), sin(π/2)) = (0, -1)
 *
 * - South (facing downwards):
 * 		angle = 3π/2
 * 		(cos(3π/2), sin(3π/2)) = (0, 1)
 *
 * - East (facing right):
 * 		angle = 0
 * 		(cos(0), sin(0)) = (1, 0)
 *
 * - West (facing left):
 * 		angle = π
 * 		(cos(π), sin(π)) = (-1, 0)
 *
 * Field of View (FOV)
 *
	- 0.66 (66 degrees) is a common value in raycasting engines for a realistic perspective.
 */
void	init_player(t_game *game)
{
	// game->move_speed = 0.05;
	// game->rot_speed = 0.03;
	find_player(game);
	if (game->player.direction == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (game->player.direction == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	else if (game->player.direction == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
	else if (game->player.direction == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (valid_player_char(game->map.map[y][x]))
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	valid_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
