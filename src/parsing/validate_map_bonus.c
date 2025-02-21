/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/21 09:37:23 by abinti-a         ###   ########.fr       */
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

bool	check_boundaries(char **map, t_point size)
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

void	assign_door_index(t_game *game, int x, int y)
{
	int	door_index;

	game->map.doors = malloc(sizeof(t_door) * game->map.door_count);
	if (!game->map.doors)
		return ;
	y = 0;
	door_index = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map.map[y]))
		{
			if (game->map.map[y][x] == 'D')
			{
				game->map.doors[door_index].x = x;
				game->map.doors[door_index].y = y;
				game->map.doors[door_index].is_open = 0;
				door_index++;
			}
			x++;
		}
		y++;
	}
}

void	count_door(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->map.door_count = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map.map[y]))
		{
			if (game->map.map[y][x] == 'D')
				game->map.door_count++;
			x++;
		}
		y++;
	}
	assign_door_index(game, x, y);
}
