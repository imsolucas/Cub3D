/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/27 14:56:06 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool find_player(t_game *game)
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
                game->player.x = j + 0.5;
                game->player.y = i + 0.5;
                game->player.direction = game->map.map[i][j];
                player_found = true;
            }
        }
    }
    return (player_found);
}

static void flood_fill_recurse(char **map, t_point pos, t_point size)
{
    if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
        return;
    if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V' || map[pos.y][pos.x] == ' ')
        return;

    char original = map[pos.y][pos.x];
    map[pos.y][pos.x] = 'V';

    flood_fill_recurse(map, (t_point){pos.x + 1, pos.y}, size);
    flood_fill_recurse(map, (t_point){pos.x - 1, pos.y}, size);
    flood_fill_recurse(map, (t_point){pos.x, pos.y + 1}, size);
    flood_fill_recurse(map, (t_point){pos.x, pos.y - 1}, size);

    if (ft_strchr("NSEW", original))
        map[pos.y][pos.x] = original;
}

static void flood_fill_map(char **map, t_point start, t_point size)
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
            if (map[i][j] == ' ')
            {
                if (i > 0 && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
                    return (false);
                if (i < size.y - 1 && map[i + 1][j] != '1' && map[i + 1][j] != ' ')
                    return (false);
                if (j > 0 && map[i][j - 1] != '1' && map[i][j - 1] != ' ')
                    return (false);
                if (j < size.x - 1 && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
                    return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}

void free_temp_map(char **map, int height)
{
    int i;

    if (!map)
        return;
    i = 0;
    while (i < height)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

bool validate_map_closed(t_game *game)
{
    char    **temp_map;
    bool    valid;
    t_point size;
    t_point start;

    if (!game->map.map || game->map.height == 0)
        return (false);
    if (!find_player(game))
        return (false);

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
