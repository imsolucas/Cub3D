/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:04:14 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/13 11:25:24 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, game->map.width,
	// 		game->map.height, "cub3D");
	// height and width are not initialized yet
	game->win = mlx_new_window(game->mlx, 1900,
			1080, "cub3D");
}
