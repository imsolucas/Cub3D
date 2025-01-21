/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/21 13:10:21 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		printf("Error\nInvalid number of arguments\n");
// 		return (1);
// 	}
// 	init_struct(&game);
// 	parse(argv[1], &game);
// 	init_game(&game);
// 	// mlx_hook(game.win, 2, 1L << 0, key_press, &game);
// 	// mlx_hook(game.win, 3, 1L << 1, key_release, &game);
// 	mlx_loop_hook(game.mlx, render_frame, &game);
// 	mlx_hook(game.win, 17, 0, cleanup, &game);
// 	mlx_loop(game.mlx);
// 	return (0);
// }

#include <stdlib.h>
#include <stdio.h>

#define MAP_WIDTH 5
#define MAP_HEIGHT 5


void init_map(t_map *map)
{
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;
    map->map = (char **)malloc(sizeof(char *) * MAP_HEIGHT);
    if (!map->map)
    {
        perror("Failed to allocate memory for map");
        exit(EXIT_FAILURE);
    }

    map->map[0] = "11111";
    map->map[1] = "10001";
    map->map[2] = "10N01";
    map->map[3] = "10001";
    map->map[4] = "11111";
}

void init_player(t_player *player, t_map *map)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            if (map->map[y][x] == 'N')
            {
                player->x = x + 0.5;
                player->y = y + 0.5;
                player->dir_x = 0.0;
                player->dir_y = -1.0;
                player->plane_x = 0.66; 
                player->plane_y = 0.0;
                return;
            }
        }
    }

    fprintf(stderr, "Player start position not found in map\n");
    exit(EXIT_FAILURE);
}

int main(void)
{
    t_map map;
	t_game game;
    t_player player;

	init_struct(&game);
	game.north.path = "textures/small-wall-1.xpm";
	game.south.path = "textures/small-wall-2.xpm";
	game.east.path = "textures/small-wall-3.xpm";
	game.west.path = "textures/small-wall-4.xpm";
    init_map(&map);
	init_game(&game);
    init_player(&player, &map);
    printf("Map:\n");
    for (int i = 0; i < map.height; i++)
        printf("%s\n", map.map[i]);
    printf("\nPlayer position: (x: %.2f, y: %.2f)\n", player.x, player.y);
    printf("Player direction: (dir_x: %.2f, dir_y: %.2f)\n", player.dir_x, player.dir_y);
    printf("Camera plane: (plane_x: %.2f, plane_y: %.2f)\n", player.plane_x, player.plane_y);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, 17, 0, cleanup, &game);
	mlx_loop(game.mlx);
	return (0);
}

