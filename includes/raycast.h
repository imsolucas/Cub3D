/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/20 15:12:44 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3d.h"

typedef struct s_player	t_player;
typedef struct s_color	t_color;
typedef struct s_game	t_game;

typedef struct s_ray
{
	double				camera_x;
	double				dir_x;
	double				dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	double				wall_x;
	int					map_x;
	int					map_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
}						t_ray;

// raycasting.c
int						raycasting(t_game *game, t_ray *ray);
void					init_raycast(t_ray *ray, t_player *player, int x);
void					init_dda(t_ray *ray, t_player *player);
void					start_dda(t_game *game, t_ray *ray);
void					calc_line_height(t_ray *ray, t_player *player);

// render.c
int						render_frame(t_game *game);
void					draw_floor_ceiling(t_game *game);
int						rgb_to_hex(t_color color);
void					put_pixel(t_game *game, int x, int y, int color);

#endif