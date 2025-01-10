/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <yourusername@student.42.fr>   +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:00:00 by yourusername      #+#    #+#            */
/*   Updated: 2025/01/10 10:00:00 by yourusername     ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	flood_fill(char **map, int x, int y, t_game *game);
static bool	is_valid_map(t_game *game);
static bool	check_borders(t_game *game);
static char	**copy_map(t_game *game);

bool	parse_map(char *line, t_game *game)
{
	char	**new_map;
	int		len;
	int		i;

	if (!game->map.map)
	{
		new_map = (char **)ft_calloc(2, sizeof(char *));
		if (!new_map)
			return (false);
		game->map.height = 1;
	}
	else
	{
		new_map = (char **)ft_calloc(game->map.height + 2, sizeof(char *));
		if (!new_map)
			return (false);
		i = 0;
		while (i < game->map.height)
		{
			new_map[i] = game->map.map[i];
			i++;
		}
		game->map.height++;
		free(game->map.map);
	}
	new_map[game->map.height - 1] = ft_strdup(line);
	if (!new_map[game->map.height - 1])
	{
		free(new_map);
		return (false);
	}
	new_map[game->map.height] = NULL;
	game->map.map = new_map;
	len = ft_strlen(line);
	if (len > game->map.width)
		game->map.width = len;
	return (true);
}

static bool	is_valid_map(t_game *game)
{
	int		x;
	int		y;
	bool	found_player;
	char	c;

	found_player = false;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			c = game->map.map[y][x];
			if (!ft_strchr("01NSEW ", c))
				return (false);
			if (ft_strchr("NSEW", c))
			{
				if (found_player)
					return (false);
				game->player.x = x;
				game->player.y = y;
				game->player.direction = c;
				found_player = true;
			}
			x++;
		}
		y++;
	}
	return (found_player);
}

static bool	check_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if ((game->map.map[0][i] != '1' && game->map.map[0][i] != ' ') ||
			(game->map.map[game->map.height - 1][i] != '1' &&
			game->map.map[game->map.height - 1][i] != ' '))
			return (false);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if ((game->map.map[i][0] != '1' && game->map.map[i][0] != ' ') ||
			(game->map.map[i][game->map.width - 1] != '1' &&
			game->map.map[i][game->map.width - 1] != ' '))
			return (false);
		i++;
	}
	return (true);
}

static bool	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (false);
	if (map[y][x] == ' ')
		return (false);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (true);
	map[y][x] = 'X';
	if (!flood_fill(map, x + 1, y, game))
		return (false);
	if (!flood_fill(map, x - 1, y, game))
		return (false);
	if (!flood_fill(map, x, y + 1, game))
		return (false);
	if (!flood_fill(map, x, y - 1, game))
		return (false);
	return (true);
}

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;
	int		j;

	copy = (char **)ft_calloc(game->map.height + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		copy[i] = (char *)ft_calloc(game->map.width + 1, sizeof(char));
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		j = 0;
		while (j < game->map.width)
		{
			copy[i][j] = game->map.map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

bool	validate_map(t_game *game)
{
	char	**map_copy;
	bool	is_valid;

	if (!is_valid_map(game) || !check_borders(game))
		return (false);
	map_copy = copy_map(game);
	if (!map_copy)
		return (false);
	is_valid = flood_fill(map_copy, game->player.x, game->player.y, game);
	while (game->map.height--)
		free(map_copy[game->map.height]);
	free(map_copy);
	return (is_valid);
}
