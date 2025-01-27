/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/27 15:23:52 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool process_line(char *line, t_game *game, int fd)
{
    int element;

    if (is_empty_line(line))
    {
        free(line);
        return (true);
    }
    element = element_type(line);
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
    free(line);
    return (true);
}

static bool validate_textures(t_game *game)
{
    if (!game->north.path || !game->south.path || 
        !game->west.path || !game->east.path)
    {
        free_texture_path(game);  // Add this line
        return (false);
    }
	if (game->floor.r == -1 || game->floor.g == -1 || game->floor.b == -1 ||
        game->ceiling.r == -1 || game->ceiling.g == -1 || game->ceiling.b == -1)
	{
		free_texture_path(game);
		return (false);
	}
    return (true);
}

static bool validate_element_order(int current_type, bool map_started)
{
    if (map_started && (current_type == TYPE_TEXTURE || current_type == TYPE_COLOR))
        return (false);
    return (true);
}

bool	parse_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	bool    map_started;
	
	map_started = false;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
    {
        int type = element_type(line);
        if (type == TYPE_MAP)
            map_started = true;
        if (!validate_element_order(type, map_started))
            return (clean_and_error(line, fd));
        if (!process_line(line, game, fd))
            return (false);
        line = get_next_line(fd);
    }
	if (!validate_textures(game))
		return (clean_and_error(NULL, fd));
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
