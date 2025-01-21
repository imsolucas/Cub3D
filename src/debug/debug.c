/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:59 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 14:02:20 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_game *game)
{
	int	i;

	i = 0;
	printf("North: %s\n", game->north.path);
	printf("South: %s\n", game->south.path);
	printf("East: %s\n", game->east.path);
	printf("West: %s\n", game->west.path);
	printf("Floor: %d %d %d\n", game->floor.r, game->floor.g, game->floor.b);
	printf("Ceiling: %d %d %d\n", game->ceiling.r,
		game->ceiling.g, game->ceiling.b);
	printf("Map:\n");
	while (i < game->map.height)
	{
		printf("%s\n", game->map.map[i]);
		i++;
	}
	printf("Player: %d %d %c\n", game->player.x, game->player.y,
		game->player.direction);
}
