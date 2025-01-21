/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 14:23:01 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	process_line(char *line, t_game *game, int fd)
{
	int	element;

	if (is_empty_line(line))
	{
		free(line);
		return (true);
	}
	element = element_type(line);
	if (element == TYPE_TEXTURE || element == TYPE_COLOR)
	{
		if (!parse_element(line, game, element))
			return (clean_and_error(line, fd));
	}
	else if (element == TYPE_MAP)
	{
		if (!parse_map(line, game))
			return (clean_and_error(line, fd));
	}
	free(line);
	return (true);
}

bool	parse_file(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line(line, game, fd))
			return (false);
		line = get_next_line(fd);
	}
	if (!validate_map_closed(game))
		return (clean_and_error(NULL, fd));
	debug(game);
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
