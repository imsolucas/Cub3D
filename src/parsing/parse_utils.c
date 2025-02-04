/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:23:31 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/04 16:25:44 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	validate_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
	return (true);
}

static void	set_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

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
	if (!validate_rgb_values(r, g, b))
	{
		free_split(split);
		return (false);
	}
	if (split[0][0] == 'F')
		set_color(&game->floor, r, g, b);
	else if (split[0][0] == 'C')
		set_color(&game->ceiling, r, g, b);
	free_split(split);
	return (true);
}

bool	parse_element(char *line, t_game *game, int element_type)
{
	char	**split;
	bool	result;

	split = ft_split_whitespace(line);
	if (!split)
		return (false);
	if (element_type == TYPE_COLOR
		&& (game->north.path || game->south.path
			|| game->west.path || game->east.path))
		result = parse_color(split, game);
	else if (element_type == TYPE_TEXTURE)
		result = parse_texture(split, game);
	else
	{
		free_split(split);
		result = false;
	}
	return (result);
}
