/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 15:08:16 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	find_player(t_game *game)
{
	bool	player_found;
	int		i;
	int		j;

	player_found = false;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width && game->map.map[i][j])
		{
			if (ft_strchr("NSEW", game->map.map[i][j]))
			{
				if (player_found)
				{
					ft_putstr_fd("Error\nMultiple players found in map\n", 2);
					return (false);
				}
				game->player.x = j + 0.5;
				game->player.y = i + 0.5;
				game->player.direction = game->map.map[i][j];
				player_found = true;
			}
		}
	}
	return (player_found);
}

static void	flood_fill_recurse(char **map, t_point pos, t_point size)
{
	char	original;

	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return ;
	if (map[pos.y][pos.x] == '1'
		|| map[pos.y][pos.x] == 'V' || map[pos.y][pos.x] == ' ')
		return ;
	original = map[pos.y][pos.x];
	map[pos.y][pos.x] = 'V';
	flood_fill_recurse(map, (t_point){pos.x + 1, pos.y}, size);
	flood_fill_recurse(map, (t_point){pos.x - 1, pos.y}, size);
	flood_fill_recurse(map, (t_point){pos.x, pos.y + 1}, size);
	flood_fill_recurse(map, (t_point){pos.x, pos.y - 1}, size);
	if (ft_strchr("NSEW", original))
		map[pos.y][pos.x] = original;
}

void	flood_fill_map(char **map, t_point start, t_point size)
{
	flood_fill_recurse(map, start, size);
}
