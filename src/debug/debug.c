/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:59 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/10 09:50:44 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_game *game)
{
	printf("North: %s\n", game->north.path);
	printf("South: %s\n", game->south.path);
	printf("East: %s\n", game->east.path);
	printf("West: %s\n", game->west.path);
	printf("Floor: %d %d %d\n", game->floor.r, game->floor.g, game->floor.b);
	printf("Ceiling: %d %d %d\n", game->ceiling.r,
		game->ceiling.g, game->ceiling.b);
	printf("Map:\n");
	for (int i = 0; i < game->map.height; i++)
		printf("%s", game->map.map[i]);
}
