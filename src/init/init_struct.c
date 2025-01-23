/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:56:23 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 15:50:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_game *game)
{
	init_struct_game(game);
	init_struct_texture(game);
	init_struct_player(game);
	init_struct_map_ray(game);
}

void	init_struct_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->addr = NULL;
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->frame_delay = 0;
}

void	init_struct_texture(t_game *game)
{
	game->north.path = NULL;
	game->north.img = NULL;
	game->north.width = 0;
	game->north.height = 0;
	game->south.path = NULL;
	game->south.img = NULL;
	game->south.width = 0;
	game->south.height = 0;
	game->east.path = NULL;
	game->east.img = NULL;
	game->east.width = 0;
	game->east.height = 0;
	game->west.path = NULL;
	game->west.img = NULL;
	game->west.width = 0;
	game->west.height = 0;
	game->floor.r = 0;
	game->floor.g = 0;
	game->floor.b = 0;
	game->ceiling.r = 0;
	game->ceiling.g = 0;
	game->ceiling.b = 0;
}

void	init_struct_player(t_game *game)
{
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->player.direction = '\0';
	game->player.move_forward = false;
	game->player.move_backward = false;
	game->player.move_left = false;
	game->player.move_right = false;
	game->player.rotate_left = false;
	game->player.rotate_right = false;
}

void	init_struct_map_ray(t_game *game)
{
	game->map.map = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->ray.camera_x = 0.0;
	game->ray.dir_x = 0.0;
	game->ray.dir_y = 0.0;
	game->ray.side_dist_x = 0.0;
	game->ray.side_dist_y = 0.0;
	game->ray.delta_dist_x = 0.0;
	game->ray.delta_dist_y = 0.0;
	game->ray.perp_wall_dist = 0.0;
	game->ray.wall_x = 0.0;
	game->ray.map_x = 0;
	game->ray.map_y = 0;
	game->ray.step_x = 0;
	game->ray.step_y = 0;
	game->ray.hit = 0;
	game->ray.side = 0;
	game->ray.tex_x = 0;
	game->ray.line_height = 0;
	game->ray.draw_start = 0;
	game->ray.draw_end = 0;
	game->ray.current_texture = NULL;
}
