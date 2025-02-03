/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:46 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/03 15:11:36 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TEXTURE_WIDTH 128
# define TEXTURE_HEIGHT 128
# define FRAME_DELAY 200

// keycodes
// # define ESC 53
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124

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

// Mouse settings
# define MOUSE_SENSITIVITY 0.00002
# define MOUSE_CENTER_X (WIN_WIDTH / 2)
# define MOUSE_CENTER_Y (WIN_HEIGHT / 2)

typedef struct s_texture
{
	char		*path;
	void		*img;
	void		*addr;
	int			width;
	int			height;
}				t_texture;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
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

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_map		map;
	t_ray		ray;
}				t_game;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

// utils.c
bool			is_empty_line(char *line);
void			free_split(char **split);
void			free_texture_path(t_game *game);
void			free_map(t_game *game);
int				element_type(char *line);
bool			clean_and_error(char *line, int fd);

int				key_press(int keycode, t_game *vars);
int				key_hook(int keycode, t_game *game);

// error.c
void			error_exit(char *message);
void			free_map(t_game *game);
int				cleanup(t_game *game);

// parse.c
void			parse(char *file, t_game *game);
bool			parse_file(char *file, t_game *game);

// parse_utils.c
bool			parse_element(char *line, t_game *game, int element_type);
bool			parse_texture(char **split, t_game *game);
bool			parse_color(char **split, t_game *game);

// parse_map.c
bool			parse_map(char *line, t_game *game);
bool			validate_map(t_game *game);

// get_next_line.c
char			*get_next_line(int fd);

// ft_split_whitespace.c
char			**ft_split_whitespace(char *str);

// init_struct.c
void			init_struct(t_game *game);
void			init_struct_game(t_game *game);
void			init_struct_texture(t_game *game);
void			init_struct_player(t_game *game);
void			init_struct_map_ray(t_game *game);

// init_game.c
void			init_game(t_game *game);
void			init_mlx(t_game *game);

// init_elements.c
void			init_texture(t_game *game);
void			get_texture_addr(t_game *game);
void			init_player(t_game *game);

// debug.c
void			debug(t_game *game);

// validate_map.c
bool			validate_map_closed(t_game *game);

// validate_map_utils.c
char			**duplicate_map(t_game *game);
bool			validate_fill(char **map, t_point size);

// direction.c
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);

// rotation.c
void			rotate_right(t_game *game);
void			rotate_left(t_game *game);

// events.c
int				loop_hook(t_game *game);
int				key_hook(int keycode, t_game *game);
void			move_player(t_game *game);
int				loop_hook(t_game *game);
int				key_release(int keycode, t_game *game);

//mouse.c
void    center_mouse(t_game *game);
int    handle_mouse(int x, int y, t_game *game);

#endif