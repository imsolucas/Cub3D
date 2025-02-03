/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 13:13:17 by abinti-a         ###   ########.fr       */
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

void	set_texture(t_game *game, t_ray *ray)
{
	ray->tex_x = (int)(ray->wall_x * game->north.width);
	if (ray->side == 0 && ray->dir_x < 0)
		ray->tex_x = game->north.width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		ray->tex_x = game->north.width  - ray->tex_x - 1;
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
	if (ray->current_texture == NULL)
    {
        printf("Error: current_texture is NULL in set_texture.\n");
        return;
    }
}

void	draw_line(t_game *game, t_ray *ray, int x)
{
	int		y;
	double	step;
	double	tex_pos;
	int		tex_y;

	set_texture(game, ray);
	step = (double)TEXTURE_HEIGHT / (double)ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2.0 + ray->line_height / 2.0) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (game->north.height - 1);
		int tex_x = ray->tex_x % game->north.width;
		if (tex_y >= 0 && tex_y < ray->current_texture->height && 
            tex_x >= 0 && tex_x < ray->current_texture->width)
        {
            unsigned int *texture_data = (unsigned int *)ray->current_texture->addr;
            unsigned int color = texture_data[tex_y * ray->current_texture->width + tex_x];
            unsigned int *image_addr = (unsigned int *)game->addr;
            if (y >= 0 && y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
                image_addr[y * WIN_WIDTH + x] = color;
        }
		// put_pixel(game, x, y, get_texture_color(ray->current_texture,
		// 	ray->tex_x, tex_y));
		tex_pos += step;
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