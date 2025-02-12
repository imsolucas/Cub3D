/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:45:31 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/12 09:54:54 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void toggle_door(t_game *game, int x, int y);

void    handle_door(t_game *game)
{
    int player_x;
    int player_y;

    player_x = (int)game->player.x;
    player_y = (int)game->player.y;

    if (game->map.map[player_y][player_x + 1] == 'D')
        toggle_door(game, player_x + 1, player_y);
    else if (game->map.map[player_y][player_x - 1] == 'D')
        toggle_door(game, player_x - 1, player_y);
    else if (game->map.map[player_y + 1][player_x] == 'D')
        toggle_door(game, player_x, player_y + 1);
    else if (game->map.map[player_y - 1][player_x] == 'D')
        toggle_door(game, player_x + 1, player_y - 1);
}

void toggle_door(t_game *game, int x, int y)
{
    int i;

    i = -1;
    while (++i < game->map.door_count)
    {
        if (game->map.doors[i].x == x && game->map.doors[i].y == y)
        {
            game->map.doors[i].is_open = !game->map.doors[i].is_open;
            if (game->map.doors[i].is_open)
                game->map.map[y][x] = '0';
            else
                game->map.map[y][x] = 'D';
            break;
        }
    }
}