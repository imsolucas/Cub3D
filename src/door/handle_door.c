/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:45:31 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/13 09:58:59 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_door(t_game *game)
{
	int		i;
	int		j;
	char	tile;
	t_check	check;

	i = -1;
	while (++i < 8)
	{
		check_player(game, &check, i);
		tile = game->map.map[check.y][check.x];
		if (tile == 'D' || tile == '0')
		{
			j = -1;
			while (++j < game->map.door_count)
			{
				if (game->map.doors[j].x == check.x
					&& game->map.doors[j].y == check.y)
				{
					toggle_door(game, check.x, check.y);
					return ;
				}
			}
		}
	}
}

void	check_player(t_game *game, t_check *check, int i)
{
	static t_direction	direction[] = {
		{1, 0},  {-1, 0},  {0, 1},  {0, -1},
		{1, 1},  {1, -1},  {-1, 1}, {-1, -1}
	};

	check->x = (int)game->player.x + direction[i].dx;
	check->y = (int)game->player.y + direction[i].dy;
}

void	toggle_door(t_game *game, int x, int y)
{
	int	i;

	// printf("Trying to toggle door at x:%d y:%d\n", x, y);
	i = -1;
	while (++i < game->map.door_count)
	{
		if (game->map.doors[i].x == x && game->map.doors[i].y == y)
		{
			game->map.doors[i].is_open = !game->map.doors[i].is_open;
			// printf("Door found! New state: %s\n", game->map.doors[i].is_open ? "open" : "closed");
			if (game->map.doors[i].is_open)
				game->map.map[y][x] = '0';
			else
				game->map.map[y][x] = 'D';
			// printf("Map tile set to: %c\n", game->map.map[y][x]);
			return ;
		}
	}
	// printf("Door not found in doors array!\n");
}
