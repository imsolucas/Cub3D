/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:20:38 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/19 14:38:14 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_map_error(void)
{
	ft_putstr_fd("Error\nInvalid map: Contains invalid character or ", 2);
	ft_putstr_fd("map is not properly closed\n", 2);
}

bool	validate_fill(char **map, t_point size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < (int)ft_strlen(map[i]))
		{
			c = map[i][j];
			if (c != '1' && c != 'V' && c != '0' && c != 'D' && c != 'C'
				&& c != ' ' && !ft_strchr("NSEW", c))
			{
				print_map_error();
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static void	free_dup_map(char **dup, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(dup[i++]);
	free(dup);
}

char	**duplicate_map(t_game *game)
{
	char	**dup;
	int		i;
	size_t	line_len;

	dup = malloc(sizeof(char *) * game->map.height);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		line_len = ft_strlen(game->map.map[i]);
		dup[i] = malloc(line_len + 1);
		if (!dup[i])
		{
			free_dup_map(dup, i);
			return (NULL);
		}
		ft_strlcpy(dup[i], game->map.map[i], line_len + 1);
		i++;
	}
	return (dup);
}
