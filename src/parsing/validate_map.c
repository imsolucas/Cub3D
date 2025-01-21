/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 17:40:47 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool    find_player(t_game *game)
{
    bool    player_found;
    int     i;
    int     j;

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
                    return (false);
                game->player.x = j;
                game->player.y = i;
                game->player.direction = game->map.map[i][j];
                player_found = true;
            }
        }
    }
    return (player_found);
}

static void	flood_fill_recurse(char **map, t_point pos, t_point size)
{
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
		return ;
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return ;
	if (map[pos.y][pos.x] == ' ')
		return ;
	map[pos.y][pos.x] = 'V';
	pos.x++;
	flood_fill_recurse(map, pos, size);
	pos.x -= 2;
	flood_fill_recurse(map, pos, size);
	pos.x++;
	pos.y++;
	flood_fill_recurse(map, pos, size);
	pos.y -= 2;
	flood_fill_recurse(map, pos, size);
}

static void	flood_fill_map(char **map, t_point start, t_point size)
{
	flood_fill_recurse(map, start, size);
}

static bool check_boundaries(char **map, t_point size)
{
    int i = 0;
    int j;

    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            if ((i == 0 || i == size.y - 1 || j == 0 || j == size.x - 1) &&
                map[i][j] != '1' && map[i][j] != ' ')
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool	validate_map_closed(t_game *game)
{
	char	**temp_map;
	bool	valid;
	t_point	size;
	t_point	start;
	int		i;

	if (!game->map.map || game->map.height == 0)
        return (false);
	if (!find_player(game))
		return (false);
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (false);
	if (!check_boundaries(temp_map, (t_point){game->map.width, game->map.height}))
	{
		free_map(game);
		free(temp_map);
		return (false);
	}
	size.x = game->map.width;
	size.y = game->map.height;
	start.x = game->player.x;
	start.y = game->player.y;
	flood_fill_map(temp_map, start, size);
	valid = validate_fill(temp_map, size);
	i = 0;
	while (i < game->map.height)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
	return (valid);
}
