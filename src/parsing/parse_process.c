/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/19 14:38:25 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	process_all_lines(int fd, t_game *game)
{
	char	*line;
	int		type;
	bool	map_started;

	map_started = false;
	line = get_next_line(fd);
	while (line)
	{
		type = element_type(line);
		if (type == TYPE_MAP)
			map_started = true;
		if (!validate_element_order(type, map_started))
			return (clean_and_error(line, fd));
		if (!process_line(line, game, fd))
			return (false);
		line = get_next_line(fd);
	}
	return (true);
}

bool	parse_file(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!process_all_lines(fd, game))
		return (false);
	if (!validate_textures(game))
		return (clean_and_error(NULL, fd));
	if (!validate_map_closed(game))
		return (clean_and_error(NULL, fd));
	return (true);
}
