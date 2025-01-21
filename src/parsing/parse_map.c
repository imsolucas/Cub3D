/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:47:18 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 14:15:45 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static bool	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\n');
}

static bool	validate_map_chars(char *line)
{
	while (*line)
	{
		if (!is_valid_map_char(*line))
			return (false);
		line++;
	}
	return (true);
}

static bool	copy_line_to_map(char *line, t_game *game, int row)
{
	int		line_len;
	char	*map_line;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	game->map.width = ft_max(game->map.width, line_len);
	map_line = malloc(sizeof(char) * (line_len + 1));
	if (!map_line)
		return (false);
	ft_strlcpy(map_line, line, line_len + 1);
	game->map.map[row] = map_line;
	return (true);
}

bool	parse_map(char *line, t_game *game)
{
	static int	row = 0;
	char		**new_map;

	if (!validate_map_chars(line))
		return (false);
	if (row == 0)
	{
		game->map.height = 0;
		game->map.width = 0;
		game->map.map = NULL;
	}
	new_map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!new_map)
		return (false);
	ft_memcpy(new_map, game->map.map, sizeof(char *) * game->map.height);
	free(game->map.map);
	game->map.map = new_map;
	game->map.height++;
	if (!copy_line_to_map(line, game, row))
		return (false);
	row++;
	return (true);
}
