/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:42 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/07 13:19:46 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_color(char **split, t_game *game)
{
	int		r;
	int		g;
	int		b;

	if (!split[1] || !split[2] || !split[3])
		return (false);
	r = ft_atoi(split[1]);
	g = ft_atoi(split[2]);
	b = ft_atoi(split[3]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (false);
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

bool	parse_element(char *line, t_game *game, int element_type)
{
	char	**split;
	// int		i;

	// i = 0;
	(void)game;
	split = ft_split_whitespace(line);
	if (!split)
		return (false);
	if (element_type == TYPE_COLOR)
		return (parse_color(split, game));
	// else if (element_type == TYPE_TEXTURE)
	// {
	// 	//return (parse_texture(split, game));
	// }
	free_split(split);
	return (false);
}

bool	parse_file(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		element_found;

	(void)game;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	while ((line = get_next_line(fd)))
	{
		if (is_empty_line(line))
		{
			free(line);
			continue ;
		}
		element_found = element_type(line);
		if (element_found == TYPE_TEXTURE || element_found == TYPE_COLOR)
			parse_element(line, game, element_found);
		free(line);
	}
	printf("Map\n");
	return (true);
}

void	parse(char *file, t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		printf("Error\nMalloc failed\n");
		exit(1);
	}
	if (!parse_file(file, game))
	{
		printf("Error\nInvalid file\n");
		exit(1);
	}
	free(game);
}
