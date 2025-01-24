/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:22:57 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/24 14:29:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MINIMAP_SIZE 200
#define MINIMAP_SCALE 30
#define MINIMAP_BORDER_COLOR 0xFFFFFF
#define MINIMAP_BACKGROUND_COLOR 0x000000

void	draw_rect(t_game *game, int x, int y, int width, int height, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height)
		{
			put_pixel(game, x + i, y + j, color);
		}
	}
}

void	draw_circle(t_game *game, int x, int y, int radius, int color)
{
	int	i;
	int	j;

	i = -radius;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				put_pixel(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_line_minimap(t_game *game, int x0, int y0, int x1, int y1,
		int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		put_pixel(game, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_minimap_grid(t_game *game)
{
	int	x;
	int	y;
	int	cell_size;
	int	color;

	cell_size = MINIMAP_SIZE / game->map.width;
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
				color = 0x444444;
			else
				color = 0x888888;
			draw_rect(game, x * cell_size, y * cell_size, cell_size, cell_size,
				color);
		}
	}
}

void	draw_square(t_game *game, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			put_pixel(game, x + i, y + j, color);
		}
	}
}

void	draw_minimap_border(t_game *game)
{
	int	border_x_start;
	int	border_y_start;
	int	border_x_end;
	int	border_y_end;
	int	x;
	int	y;

	border_x_start = 0;
	border_y_start = 0;
	border_x_end = game->map.width * MINIMAP_SCALE + 4;
	border_y_end = game->map.height * MINIMAP_SCALE + 4;
	y = border_y_start;
	while (y < border_y_end)
	{
		x = border_x_start;
		while (x < border_x_end)
		{
			if (x == border_x_start || x == border_x_end - 1
				|| y == border_y_start || y == border_y_end - 1)
				put_pixel(game, x, y, MINIMAP_BORDER_COLOR);
			else
				put_pixel(game, x, y, MINIMAP_BACKGROUND_COLOR);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	int		x;
	int		y;
	double	ray_x;
	double	ray_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;

	draw_minimap_border(game);
	y = -1;
	while (++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
		{
			if (game->map.map[y][x] == '1')
				draw_square(game, x * MINIMAP_SCALE + 2, y * MINIMAP_SCALE + 2,
					MINIMAP_SCALE, 0x333333);
			else if (game->map.map[y][x] == '0')
				draw_square(game, x * MINIMAP_SCALE + 2, y * MINIMAP_SCALE + 2,
					MINIMAP_SCALE, 0x666666);
		}
	}
	draw_square(game, (int)((game->player.x - 0.5) * MINIMAP_SCALE) + 2
		+ (MINIMAP_SCALE / 3) / 2, (int)((game->player.y - 0.5) * MINIMAP_SCALE)
		+ 2 + (MINIMAP_SCALE / 3) / 2, MINIMAP_SCALE, 0xFFFF00);
	ray_x = game->player.x;
	ray_y = game->player.y;
	ray_dir_x = game->player.dir_x;
	ray_dir_y = game->player.dir_y;
	while (1)
	{
		map_x = (int)ray_x;
		map_y = (int)ray_y;
		if (map_x < 0 || map_y < 0 || map_x >= game->map.width
			|| map_y >= game->map.height || game->map.map[map_y][map_x] == '1')
			break ;
		draw_square(game, (int)(ray_x * MINIMAP_SCALE) + 2, (int)(ray_y
				* MINIMAP_SCALE) + 2, MINIMAP_SCALE / 5, 0xFF0000);
		ray_x += ray_dir_x * 0.1;
		ray_y += ray_dir_y * 0.1;
	}
}
