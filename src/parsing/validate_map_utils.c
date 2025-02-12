/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 13:30:42 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_fill(char **map, t_point size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			c = map[i][j];
			if (c != '1' && c != 'V' && c != '0'
				&& c != ' ' && !ft_strchr("NSEW", c))
			{
				ft_putstr_fd("Error\nInvalid map: Contains invalid character or map is not properly closed\n", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

char	**duplicate_map(t_game *game)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * game->map.height);
	if (!dup)
	{
		ft_putstr_fd("Error\nMemory allocation failed during map validation\n", 2);
		return (NULL);
	}
	i = 0;
	while (i < game->map.height)
	{
		dup[i] = ft_strdup(game->map.map[i]);
		if (!dup[i])
		{
			ft_putstr_fd("Error\nMemory allocation failed during map validation\n", 2);
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	return (dup);
}
