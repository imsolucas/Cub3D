/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:17 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:42:25 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

/* ************************** */
/*         INCLUDES          */
/* ************************** */
# include "cub3d.h"

/* ************************** */
/*     MINIMAP SETTINGS      */
/* ************************** */
# define MINIMAP_SCALE 15
# define MINIMAP_BORDER_COLOR 0xFFFFFF
# define MINIMAP_BACKGROUND_COLOR 0x000000

/* ************************** */
/*   STRUCTURE REFERENCES    */
/* ************************** */
typedef struct s_player			t_player;
typedef struct s_color			t_color;
typedef struct s_game			t_game;
typedef struct s_texture		t_texture;

/* ************************** */
/*      RAY STRUCTURE        */
/* ************************** */
typedef struct s_ray
{
	double					camera_x;
	double					dir_x;
	double					dir_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	double					wall_x;
	int						map_x;
	int						map_y;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						tex_x;
	int						line_height;
	int						draw_start;
	int						draw_end;
	t_texture				*current_texture;
}							t_ray;

/* ************************** */
/*    MINIMAP STRUCTURE      */
/* ************************** */
typedef struct s_mini
{
	double					ray_x;
	double					ray_y;
	double					ray_dir_x;
	double					ray_dir_y;
	int						map_x;
	int						map_y;
	int						border_x_start;
	int						border_y_start;
	int						x;
	int						y;
	int						size;
	int						color;
}							t_mini;

/* ************************** */
/*       RAYCASTING          */
/* ************************** */
int							raycasting(t_game *game, t_ray *ray);
void						init_raycast(t_ray *ray, t_player *player, int x);
void						init_dda(t_ray *ray, t_player *player);
void						start_dda(t_game *game, t_ray *ray);
void						calc_line_height(t_ray *ray, t_player *player);

/* ************************** */
/*         DRAWING           */
/* ************************** */
void						draw_floor_ceiling(t_game *game);
void						draw_line(t_game *game, t_ray *ray, int x);
void						set_texture(t_game *game, t_ray *ray);
void						draw_texture(t_game *game, int x, int y,
								int tex_pos);
int							render_frame(t_game *game);
int							rgb_to_hex(t_color color);
void						put_pixel(t_game *game, int x, int y, int color);
int							get_texture_color(t_texture *texture, int x,
								int y);

/* ************************** */
/*         MINIMAP           */
/* ************************** */
void						draw_minimap(t_game *game);
void						draw_minimap_border(t_game *game, t_mini *mini);
void						draw_minimap_floor(t_game *game);
void						draw_minimap_player(t_game *game);
void						draw_square(t_game *game, t_mini *mini);
void						init_minimap(t_game *game, t_mini *mini);

#endif