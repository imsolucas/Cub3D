/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 14:11:13 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	validate_fill(char **map, t_point size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] != '1' && map[i][j] != 'V' && map[i][j] != ' ')
				return (false);
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
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		dup[i] = ft_strdup(game->map.map[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	return (dup);
}
