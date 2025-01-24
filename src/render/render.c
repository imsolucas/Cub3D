/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/24 14:30:09 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	raycasting(game, &game->ray);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel(game, x, y, rgb_to_hex(game->ceiling));
			else
				put_pixel(game, x, y, rgb_to_hex(game->floor));
			x++;
		}
		y++;
	}
}

// Solid color testing

// void draw_line(t_game *game, t_ray *ray, int x)
// {
//     int y = 0;
//     int wall_color;
//     if (ray->side == 0)
//         wall_color = 0xFF0000;
//     else
//         wall_color = 0x880000;
//     while (y < WIN_HEIGHT)
//     {
//         if (y < ray->draw_start)
//             put_pixel(game, x, y, rgb_to_hex(game->ceiling));
//         else if (y >= ray->draw_start && y <= ray->draw_end)
//             put_pixel(game, x, y, wall_color);
//         else
//             put_pixel(game, x, y, rgb_to_hex(game->floor));
//         y++;
//     }
// }

void	set_texture(t_game *game, t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * TEXTURE_WIDTH);
	if (ray->side == 0 && ray->dir_x < 0)
		ray->tex_x = TEXTURE_WIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		ray->tex_x = TEXTURE_WIDTH - ray->tex_x - 1;
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			ray->current_texture = &game->west;
		else
			ray->current_texture = &game->east;
	}
	else
	{
		if (ray->dir_y > 0)
			ray->current_texture = &game->north;
		else
			ray->current_texture = &game->south;
	}
}

void	draw_line(t_game *game, t_ray *ray, int x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;

	set_texture(game, ray);
	step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < ray->draw_start)
			put_pixel(game, x, y, rgb_to_hex(game->ceiling));
		else if (y <= ray->draw_end)
		{
			tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
			tex_pos += step;
			put_pixel(game, x, y, get_texture_color(ray->current_texture,
					ray->tex_x, tex_y));
		}
		else
			put_pixel(game, x, y, rgb_to_hex(game->floor));
		y++;
	}
}
