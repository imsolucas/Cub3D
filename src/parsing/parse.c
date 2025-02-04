/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/04 17:18:51 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	handle_element(char *line, t_game *game, int fd, int element)
{
	if (element == TYPE_TEXTURE || element == TYPE_COLOR)
	{
		if (!parse_element(line, game, element))
		{
			free(line);
			close(fd);
			return (false);
		}
	}
	else if (element == TYPE_MAP)
	{
		if (!parse_map(line, game))
		{
			free(line);
			close(fd);
			return (false);
		}
	}
	return (true);
}

bool	process_line(char *line, t_game *game, int fd)
{
	int	element;

	if (is_empty_line(line))
	{
		free(line);
		return (true);
	}
	element = element_type(line);
	if (!handle_element(line, game, fd, element))
		return (false);
	free(line);
	return (true);
}

void	parse(char *file, t_game *game)
{
	if (!parse_file(file, game))
	{
		printf("Error\nInvalid file\n");
		exit(1);
	}
}
