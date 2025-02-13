/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:58:50 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/13 11:05:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

void	free_doors(t_game *game)
{
	if (game->map.doors)
	{
		free(game->map.doors);
		game->map.doors = NULL;
	}
}

void	free_img(t_game *game)
{
	if (game->north.img)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx, game->west.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->door_open.img)
		mlx_destroy_image(game->mlx, game->door_open.img);
	if (game->door_close.img)
		mlx_destroy_image(game->mlx, game->door_close.img);
}

int	cleanup(t_game *game)
{
	free_img(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	free_doors(game);
	free_texture_path(game);
	free(game);
	exit(0);
	return (0);
}

void	free_temp_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
