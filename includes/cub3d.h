/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:46 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/13 10:45:55 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************** */
/*          INCLUDES         */
/* ************************** */
# include "enum.h"
# include "libft.h"
# include "mlx.h"
# include "raycast.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************** */
/*          DEFINES          */
/* ************************** */
# define WIN_WIDTH 1000
# define WIN_HEIGHT 880
# define TEXTURE_WIDTH 128
# define TEXTURE_HEIGHT 128
# define FRAME_DELAY 500

/* ************************** */
/*         KEY CODES         */
/* ************************** */
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define SHIFT 65505

# define W 119
# define A 97
# define S 115
# define D 100
# define P 112

/* ************************** */
/*      MOUSE SETTINGS       */
/* ************************** */
# define MOUSE_SENSITIVITY 0.0002
# define MOUSE_CENTER_X 300
# define MOUSE_CENTER_Y 240

/* ************************** */
/*        STRUCTURES         */
/* ************************** */
typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_texture
{
	char		*path;
	void		*img;
	void		*addr;
	int			width;
	int			height;
}				t_texture;

typedef struct s_door
{
	int			x;
	int			y;
	int			is_open;
}				t_door;

typedef struct s_check
{
	int			x;
	int			y;
}				t_check;

typedef struct t_direction
{
	int			dx;
	int			dy;
}				t_direction;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;


typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			door_count;
	t_door		*doors;
}				t_map;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		direction;
	bool		move_forward;
	bool		move_backward;
	bool		move_left;
	bool		move_right;
	bool		rotate_left;
	bool		rotate_right;
	bool		sprint;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			frame_delay;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	door_open;
	t_texture	door_close;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_map		map;
	t_ray		ray;
	t_direction	*direction;
	t_check		*check;
}				t_game;

/* ************************** */
/*      INITIALIZATION       */
/* ************************** */
void			init_game(t_game *game);
void			init_mlx(t_game *game);
void			init_struct(t_game *game);
void			init_struct_game(t_game *game);
void			init_struct_texture(t_game *game);
void			init_struct_player(t_game *game);
void			init_struct_map_ray(t_game *game);
void			init_texture(t_game *game);
void			get_texture_addr(t_game *game);
void			init_player(t_game *game);

/* ************************** */
/*         PARSING           */
/* ************************** */
void			parse(char *file, t_game *game);
bool			parse_file(char *file, t_game *game);
bool			parse_element(char *line, t_game *game, int element_type);
bool			parse_texture(char **split, t_game *game);
bool			parse_color(char **split, t_game *game);
bool			parse_map(char *line, t_game *game);
bool			process_line(char *line, t_game *game, int fd);

/* ************************** */
/*        VALIDATION         */
/* ************************** */
bool			validate_map(t_game *game);
bool			validate_textures(t_game *game);
bool			validate_element_order(int current_type, bool map_started);
bool			validate_map_closed(t_game *game);
bool			validate_fill(char **map, t_point size);
bool			find_player(t_game *game);
void			flood_fill_map(char **map, t_point start, t_point size);

/* ************************** */
/*         MOVEMENT          */
/* ************************** */
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
int				can_move(t_game *game, int y, int x);

// rotation.c
void			rotate_right(t_game *game);
void			rotate_left(t_game *game);
void			move_player(t_game *game);

/* ************************** */
/*          EVENTS           */
/* ************************** */
int				loop_hook(t_game *game);
int				key_hook(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				handle_mouse(int x, int y, t_game *game);
void			center_mouse(t_game *game);

/* ************************** */
/*         UTILITIES         */
/* ************************** */
bool			is_empty_line(char *line);
void			free_split(char **split);
void			free_texture_path(t_game *game);
void			free_map(t_game *game);
void			free_temp_map(char **map, int height);
int				element_type(char *line);
bool			clean_and_error(char *line, int fd);
char			**duplicate_map(t_game *game);
char			**ft_split_whitespace(char *str);
char			*get_next_line(int fd);
void			debug(t_game *game);
void			error_exit(char *message);
int				cleanup(t_game *game);

// handle_door.c
void			handle_door(t_game *game);
void			check_player(t_game *game, t_check *check, int i);
void			toggle_door(t_game *game, int x, int y);

#endif