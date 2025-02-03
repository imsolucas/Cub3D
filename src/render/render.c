/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:41:56 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 16:45:22 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *game)
{
	draw_floor_ceiling(game);
	raycasting(game, &game->ray);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}
