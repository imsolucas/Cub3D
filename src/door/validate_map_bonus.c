/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/13 10:41:06 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	flood_fill_map(char **map, t_point start, t_point size);

static bool	check_space_neighbors(char **map, int i, int j, t_point size)
{
	if (i > 0 && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
		return (false);
	if (i < size.y - 1 && map[i + 1][j] != '1' && map[i + 1][j] != ' ')
		return (false);
	if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ')
		return (false);
	if (j < size.x - 1 && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
		return (false);
	return (true);
}

static bool	check_boundaries(char **map, t_point size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size.y)
	{
		j = -1;
		while (++j < size.x)
		{
			if ((i == 0 || i == size.y - 1 || j == 0 || j == size.x - 1)
				&& map[i][j] != '1' && map[i][j] != ' ')
				return (false);
			if (map[i][j] == ' ' && !check_space_neighbors(map, i, j, size))
				return (false);
		}
	}
	return (true);
}

void count_door(t_game *game)
{
    int x;
    int y;
    int door_index;
    
    x = 0;
    game->map.door_count = 0;
    while (x < game->map.height)
    {
        y = 0;
        while (y < game->map.width)
        {
            if (game->map.map[x][y] == 'D')
                game->map.door_count++;
            y++;
        }
        x++;
    }
    game->map.doors = malloc(sizeof(t_door) * game->map.door_count);
    if (!game->map.doors)
        return; 
    x = 0;
    door_index = 0;
    
    while (x < game->map.height)
    {
        y = 0;
        while (y < game->map.width)
        {
            if (game->map.map[x][y] == 'D')
            {
                game->map.doors[door_index].x = y;
                game->map.doors[door_index].y = x;
                game->map.doors[door_index].is_open = 0;
                door_index++;
            }
            y++;
        }
        x++;
    }
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
    count_door(game);
	temp_map = duplicate_map(game);
	if (!temp_map)
		return (false);
	size = (t_point){game->map.width, game->map.height};
	start = (t_point){(int)game->player.x, (int)game->player.y};
	if (!check_boundaries(temp_map, size))
	{
		free_temp_map(temp_map, game->map.height);
		return (false);
	}
	flood_fill_map(temp_map, start, size);
	valid = validate_fill(temp_map, size);
	free_temp_map(temp_map, game->map.height);
	return (valid);
}
