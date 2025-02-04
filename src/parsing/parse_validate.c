/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/04 17:19:14 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_textures(t_game *game)
{
	if (!game->north.path || !game->south.path
		|| !game->west.path || !game->east.path)
	{
		free_texture_path(game);
		return (false);
	}
	if (game->floor.r == -1 || game->floor.g == -1 || game->floor.b == -1
		|| game->ceiling.r == -1 || game->ceiling.g == -1
		|| game->ceiling.b == -1)
	{
		free_texture_path(game);
		return (false);
	}
	return (true);
}

bool	validate_element_order(int current_type, bool map_started)
{
	if (map_started && (current_type == TYPE_TEXTURE
			|| current_type == TYPE_COLOR))
		return (false);
	return (true);
}
