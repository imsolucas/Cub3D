/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:58:50 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/13 12:30:59 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

void cleanup(t_game *game)
{
    if (game->north.img)
        mlx_destroy_image(game->mlx, game->north.img);
    if (game->south.img)
        mlx_destroy_image(game->mlx, game->south.img);
    if (game->west.img)
        mlx_destroy_image(game->mlx, game->west.img);
    if (game->east.img)
        mlx_destroy_image(game->mlx, game->east.img);
    if (game->img)
        mlx_destroy_image(game->mlx, game->img);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    if (game->map.map)
        free_map(game);
}
