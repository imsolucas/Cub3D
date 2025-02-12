/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_flood.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 15:33:28 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	update_player_pos(t_game *game, int i, int j)
{
	game->player.x = j + 0.5;
	game->player.y = i + 0.5;
	game->player.direction = game->map.map[i][j];
	return (true);
}

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
				player_found = update_player_pos(game, i, j);
			}
		}
	}
	return (player_found);
}
