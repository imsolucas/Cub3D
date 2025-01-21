/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/21 13:09:34 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	raycasting(game, &game->ray);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void draw_line(t_game *game, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < ray->draw_start)
			put_pixel(game, x, y, rgb_to_hex(game->ceiling));
		else if (y >= ray->draw_start && y <= ray->draw_end)
		{
			// if (ray->side == 0)
			// 	//put_pixel(game, x, y, rgb_to_hex(game->north[y][x]));
			// else
			// 	//put_pixel(game, x, y, rgb_to_hex(game->south.color));
		}
		else
			put_pixel(game, x, y, rgb_to_hex(game->floor));
		y++;
	}
}

// void	draw_floor_ceiling(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIN_WIDTH)
// 		{
// 			if (y < WIN_HEIGHT / 2)
// 				put_pixel(game, x, y, rgb_to_hex(game->ceiling));
// 			else
// 				put_pixel(game, x, y, rgb_to_hex(game->floor));
// 			x++;
// 		}
// 		y++;
// 	}
// }

int	rgb_to_hex(t_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
