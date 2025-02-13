/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:50:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 15:33:32 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_pos(t_point pos, t_point size)
{
	return (pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y);
}

static void	flood_fill_recurse(char **map, t_point pos, t_point size)
{
	char	original;

	if (!is_valid_pos(pos, size))
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
