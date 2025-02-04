/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:24:44 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/04 16:24:51 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	set_texture_path(t_texture *texture, char *path)
{
	if (texture->path)
		return (false);
	texture->path = ft_strdup(path);
	return (true);
}

static bool	assign_texture(char *id, char *path, t_game *game)
{
	if (!ft_strcmp(id, "NO"))
		return (set_texture_path(&game->north, path));
	if (!ft_strcmp(id, "SO"))
		return (set_texture_path(&game->south, path));
	if (!ft_strcmp(id, "WE"))
		return (set_texture_path(&game->west, path));
	if (!ft_strcmp(id, "EA"))
		return (set_texture_path(&game->east, path));
	return (false);
}

bool	parse_texture(char **split, t_game *game)
{
	bool	result;

	if (!split[1] || split[2])
	{
		free_split(split);
		return (false);
	}
	result = assign_texture(split[0], split[1], game);
	free_split(split);
	return (result);
}
