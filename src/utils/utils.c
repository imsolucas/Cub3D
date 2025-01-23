/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:09:39 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/23 14:14:45 by abinti-a         ###   ########.fr       */
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

	if (!split)
		return ;
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

bool	clean_and_error(char *line, int fd)
{
	if (line)
		free(line);
	if (fd > 0)
		close(fd);
	return (false);
}
