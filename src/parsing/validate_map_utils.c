/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/04 16:42:33 by imsolucas        ###   ########.fr       */
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
				printf("Error\nInvalid map hi\n");
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
