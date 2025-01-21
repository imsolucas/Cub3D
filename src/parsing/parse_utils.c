/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:23:31 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 17:39:42 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_color(char **split, t_game *game)
{
	int		r;
	int		g;
	int		b;

	if (!split[1] || !split[2] || !split[3])
	{
		free_split(split);
		return (false);
	}
	r = ft_atoi(split[1]);
	g = ft_atoi(split[2]);
	b = ft_atoi(split[3]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_split(split);
		return (false);
	}
	if (split[0][0] == 'F')
	{
		game->floor.r = r;
		game->floor.g = g;
		game->floor.b = b;
	}
	else if (split[0][0] == 'C')
	{
		game->ceiling.r = r;
		game->ceiling.g = g;
		game->ceiling.b = b;
	}
	free_split(split);
	return (true);
}

bool	parse_texture(char **split, t_game *game)
{
	if (!split[1] || split[2])
		return (false);
	if (ft_strcmp(split[0], "NO") == 0)
	{
		if (game->north.path)
			return (false);
		game->north.path = ft_strdup(split[1]);
	}
	else if (ft_strcmp(split[0], "SO") == 0)
	{
		if (game->south.path)
			return (false);
		game->south.path = ft_strdup(split[1]);
	}
	else if (ft_strcmp(split[0], "WE") == 0)
	{
		if (game->west.path)
			return (false);
		game->west.path = ft_strdup(split[1]);
	}
	else if (ft_strcmp(split[0], "EA") == 0)
	{
		if (game->east.path)
			return (false);
		game->east.path = ft_strdup(split[1]);
	}
	else
	{
		free_split(split);
		return (false);
	}
	free_split(split);
	return (true);
}

bool	parse_element(char *line, t_game *game, int element_type)
{
	char	**split;

	split = ft_split_whitespace(line);
	if (!split)
		return (false);
	if (element_type == TYPE_COLOR)
		return (parse_color(split, game));
	else if (element_type == TYPE_TEXTURE)
		return (parse_texture(split, game));
	free_split(split);
	return (false);
}
