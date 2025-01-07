/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:46 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/07 11:23:46 by imsolucas        ###   ########.fr       */
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
// # include "mlx.h"

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
	int		rows;
	int		cols;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_game
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
}	t_game;

// utils.c
bool	is_empty_line(char *line);
void	free_split(char **split);
int		element_type(char *line);

// parse.c
void	parse(char *file, t_game *game);

// get_next_line.c
char	*get_next_line(int fd);

// ft_split_whitespace.c
char	**ft_split_whitespace(char *str);

#endif