/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:46 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/13 11:22:17 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>
# include "enum.h"
# include "mlx.h"

typedef struct s_texture
{
	char	*path;
	void	*img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_player // New structure for player
{
	int		x;
	int		y;
	char	direction; // N, S, E, or W
}	t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_map		map;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// utils.c
bool	is_empty_line(char *line);
void	free_split(char **split);
void	free_texture_path(t_game *game);
void	free_map(t_game *game);
int		element_type(char *line);
bool	clean_and_error(char *line, int fd);

// parse.c
void	parse(char *file, t_game *game);

// parse_map.c
bool	parse_map(char *line, t_game *game);
bool	validate_map(t_game *game);

// get_next_line.c
char	*get_next_line(int fd);

// ft_split_whitespace.c
char	**ft_split_whitespace(char *str);

// init_mlx.c
void	init_mlx(t_game *game);

// init_elements.c
void	init_texture(t_game *game);

// debug.c
void	debug(t_game *game);

#endif