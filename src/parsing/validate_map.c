/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/19 16:11:24 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_pos(int i, int j, char **map, t_point size)
{
	if (i < 0 || i >= size.y)
		return (false);
	if (j < 0 || j >= (int)ft_strlen(map[i]))
		return (false);
	return (true);
}

static bool	is_surrounded_by_walls(char **map, int i, int j, t_point size)
{
	if (!is_valid_pos(i - 1, j, map, size) || \
		map[i - 1][j] == ' ' || j >= (int)ft_strlen(map[i - 1]))
		return (false);
	if (!is_valid_pos(i + 1, j, map, size) || \
		map[i + 1][j] == ' ' || j >= (int)ft_strlen(map[i + 1]))
		return (false);
	if (!is_valid_pos(i, j - 1, map, size) || map[i][j - 1] == ' ')
		return (false);
	if (!is_valid_pos(i, j + 1, map, size) || map[i][j + 1] == ' ')
		return (false);
	return (true);
}

static bool	check_boundary(char **map, t_point size)
{
	int	i;
	int	j;
	int	line_len;

	i = -1;
	while (++i < size.y)
	{
		line_len = ft_strlen(map[i]);
		j = -1;
		while (++j < line_len)
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (!is_surrounded_by_walls(map, i, j, size))
					return (false);
			}
		}
	}
	return (true);
}

bool	validate_map_closed(t_game *game)
{
	char	**temp_map;
	bool	valid;
	t_point	size;
	t_point	start;

	if (!game->map.map || game->map.height == 0)
		return (false);
	if (!find_player(game))
		return (false);
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (false);
	size = (t_point){game->map.width, game->map.height};
	start = (t_point){(int)game->player.x, (int)game->player.y};
	if (!check_boundary(temp_map, size))
	{
		free_temp_map(temp_map, game->map.height);
		return (false);
	}
	flood_fill_map(temp_map, start, size);
	valid = validate_fill(temp_map, size);
	free_temp_map(temp_map, game->map.height);
	return (valid);
}
