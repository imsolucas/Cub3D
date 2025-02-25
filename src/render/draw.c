/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/19 13:29:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/**
 * step = how much to increase the texture coordinate per screen pixel
 * tex_pos = starting texture coordinate (we need to fit the texture 
 * to draw_start and draw end)
 * tex_pos is incremented by step in each loop move to the next 
 * texture coordinate (down the column)
 */
void	draw_line(t_game *game, t_ray *ray, int x)
{
	int		y;
	double	step;
	double	tex_pos;

	set_texture(game, ray);
	step = (double)TEXTURE_HEIGHT / (double)ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2.0 + ray->line_height / 2.0)
		* step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		draw_texture(game, x, y, tex_pos);
		tex_pos += step;
		y++;
	}
}

/**
 * tex_x = determines which column of the texture to use
 * 
 * When ray hits left/downward wall, the texture will look reversed. 
 * Need to be corrected
 */
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

void	draw_texture(t_game *game, int x, int y, int tex_pos)
{
	int				tex_x;
	int				tex_y;
	unsigned int	*texture_data;
	unsigned int	color;
	unsigned int	*image_addr;

	tex_x = game->ray.tex_x % TEXTURE_WIDTH;
	tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
	if (tex_y >= 0 && tex_y < TEXTURE_HEIGHT && tex_x >= 0
		&& tex_x < TEXTURE_WIDTH)
	{
		texture_data = (unsigned int *)game->ray.current_texture->addr;
		color = texture_data[tex_y * TEXTURE_WIDTH + tex_x];
		image_addr = (unsigned int *)game->addr;
		if (y >= 0 && y < WIN_HEIGHT && x >= 0 && x < WIN_WIDTH)
			image_addr[y * WIN_WIDTH + x] = color;
	}
}
