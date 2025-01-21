/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:07:52 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/21 11:11:27 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_game *game, t_ray *ray)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_raycast(ray, &game->player, x);
		init_dda(ray, &game->player);
		start_dda(game, ray);
		calc_line_height(ray, &game->player);
		draw_line(game, ray, x);
		x++;
	}
	return (0);
}

/**
 * camera_x: x-coordinate in camera space (range from -1 to 1)
 *
 * ray->dir_x and ray->dir_y: direction vector of the ray
 * -ray->dir_x > 0 if ray points to the right
 * -ray->dir_x < 0 if ray points to the left
 * -ray->dir_y < 0 if ray points upwards
 * -ray->dir_y > 0 if ray points downwards
 *
 * player's x and y typcasted to int to get the map square the player is in
 *
 * delta_dist_x and delta_dist_y: length of ray from one x or y-side to next x or y-side
 */
void	init_raycast(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

/**
 * x increases as you move right
 * y increases as you move down
 */
void	init_dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

/**
 * In DDA, the shorter side_dist is chosen to move the ray to the next square
 */
void	start_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= game->map.width || ray->map_y < 0
			|| ray->map_y >= game->map.height)
			break ;
		else if (game->map.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

/**
 * perp_wall_dist = distance from the player to the wall along the ray's path
 * perp_wall_dist is adjusted to avoid fish-eye distortion by considering 
 * only the perpendicular component of the distance.
 * 
 * The wall's height on the screen is inversely proportional to perp_wall_dist
 * 
 * wall_x represents the exact position along the wall that was hit (in the range [0, 1]).
 * If the wall was hit along the x-axis (side == 0), the wall's position is calculated based 
 * on the player's y position and the y-component of the ray's direction.
 * If the wall was hit along the y-axis (side == 1), the position is based on the player's x 
 * position and the x-component of the ray's direction.
 * 
 * floor() = round down to the nearest integer
 * floor() removes the integer part of ray->wall_x, leaving just the fractional part
 * This fractional part is then used to map a specific portion of the texture to the wall being rendered
 */
void	calc_line_height(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->hit == 0)
		ray->wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}
