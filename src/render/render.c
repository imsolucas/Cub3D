/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/23 11:27:07 by abinti-a         ###   ########.fr       */
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
    int y;
    int color;

    y = ray->draw_start;
    while (y <= ray->draw_end)
    {
        // Set color based on wall side (add shading for depth effect)
        if (ray->side == 0)
            color = 0xFFFFFF; // Bright color for x-side walls
        else
            color = 0xAAAAAA; // Dim color for y-side walls

        // Draw the pixel
        mlx_pixel_put(game->mlx, game->win, x, y, color);
        y++;
    }
}


int get_texture_color(t_texture *texture, int x, int y)
{
    char *dst;
    
    dst = texture->addr + (y * texture->width + x * 4);
    return (*(unsigned int*)dst);
}

// void draw_line(t_game *game, t_ray *ray, int x)
// {
//     // Calculate texture X coordinate
//     int tex_x = (int)(ray->wall_x * TEXTURE_WIDTH);
    
//     // Flip texture X coordinate based on wall side and ray direction
//     if (ray->side == 0 && ray->dir_x > 0)
//         tex_x = TEXTURE_WIDTH - tex_x - 1;
//     if (ray->side == 1 && ray->dir_y < 0)
//         tex_x = TEXTURE_WIDTH - tex_x - 1;

//     // Select texture based on which wall was hit
//     t_texture *current_texture;
//     if (ray->side == 0)  // Vertical wall (East/West)
//     {
//         if (ray->dir_x > 0)
//             current_texture = &game->west;
//         else
//             current_texture = &game->east;
//     }
//     else  // Horizontal wall (North/South)
//     {
//         if (ray->dir_y > 0)
//             current_texture = &game->north;
//         else
//             current_texture = &game->south;
//     }

//     // Calculate texture step and initial position
//     double step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
//     double tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;

//     // Draw the wall line
//     int y = 0;
//     while (y < WIN_HEIGHT)
//     {
//         if (y < ray->draw_start)
//             put_pixel(game, x, y, rgb_to_hex(game->ceiling));
//         else if (y <= ray->draw_end)
//         {
//             int tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
//             tex_pos += step;

//             // Get color from texture
//             unsigned int *texture_data = (unsigned int *)current_texture->addr;
//             int color = texture_data[TEXTURE_HEIGHT * tex_y + tex_x];

//             // Make color darker for y-sides (optional)
//             if (ray->side == 1)
//                 color = (color >> 1) & 8355711;

//             put_pixel(game, x, y, color);
//         }
//         else
//             put_pixel(game, x, y, rgb_to_hex(game->floor));
//         y++;
//     }
// }




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
