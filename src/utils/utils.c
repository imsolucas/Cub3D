/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:09:39 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/10 09:52:09 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ')
			return (false);
		line++;
	}
	return (true);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void	free_texture_path(t_game *game)
{
	if (game->north.path)
		free(game->north.path);
	if (game->south.path)
		free(game->south.path);
	if (game->west.path)
		free(game->west.path);
	if (game->east.path)
		free(game->east.path);
}

// check for .cub type wether if it's texture, color or map
int	element_type(char *line)
{
	char	**split;
	int		type;

	if (!line || !*line)
		return (TYPE_EMPTY);
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (TYPE_EMPTY);
	if (*line == '1' || *line == ' ' || *line == '0')
	{
		while (*line && *line != '\n')
		{
			if (!ft_strchr(" 01NSEW", *line))
				return (TYPE_ERROR);
			line++;
		}
		return (TYPE_MAP);
	}
	split = ft_split(line, ' ');
	if (!split)
		return (TYPE_ERROR);
	type = TYPE_ERROR;
	if (!split[0])
	{
		free_split(split);
		return (TYPE_ERROR);
	}
	if (ft_strlen(split[0]) == 2)
	{
		if (!ft_strncmp(split[0], "NO", 2) || !ft_strncmp(split[0], "SO", 2)
			|| !ft_strncmp(split[0], "WE", 2) || !ft_strncmp(split[0], "EA", 2))
			type = TYPE_TEXTURE;
	}
	else if (ft_strlen(split[0]) == 1)
	{
		if (split[0][0] == 'F' || split[0][0] == 'C')
			type = TYPE_COLOR;
	}
	free_split(split);
	return (type);
}

bool	clean_and_error(char *line, int fd)
{
	if (line)
		free(line);
	if (fd > 0)
		close(fd);
	return (false);
}
