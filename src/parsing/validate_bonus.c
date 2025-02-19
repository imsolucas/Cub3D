/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:13:28 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/19 15:13:40 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
