/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:24:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 14:11:21 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->north.path,
			&game->north.width, &game->north.height);
	if (!game->north.img)
		error_exit("Failed to load North texture");
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->south.path,
			&game->south.width, &game->south.height);
	if (!game->south.img)
		error_exit("Failed to load South texture");
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->east.path,
			&game->east.width, &game->east.height);
	if (!game->east.img)
		error_exit("Failed to load East texture");
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->west.path,
			&game->west.width, &game->west.height);
	if (!game->west.img)
		error_exit("Failed to load West texture");
	get_texture_addr(game);
}

void	get_texture_addr(t_game *game)
{
	int	tmp_bpp;
	int	tmp_line_len;
	int	tmp_endian;

	game->north.addr = mlx_get_data_addr(game->north.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->north.addr)
		error_exit("Failed to get North texture address");
	game->south.addr = mlx_get_data_addr(game->south.img, &tmp_bpp,
			&tmp_line_len, &tmp_endian);
	if (!game->south.addr)
		error_exit("Failed to get South texture adress");
	game->east.addr = mlx_get_data_addr(game->east.img, &tmp_bpp, &tmp_line_len,
			&tmp_endian);
	if (!game->east.addr)
		error_exit("Failed to get East texture address");
	game->west.addr = mlx_get_data_addr(game->west.img, &tmp_bpp, &tmp_line_len,
			&tmp_endian);
	if (!game->west.addr)
		error_exit("Failed to get West texture address");
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
 * - 0.66 (66 degrees) is a common value in raycasting engines 
 *   for a realistic perspective.
 */
void	init_player(t_game *game)
{
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
