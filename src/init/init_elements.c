/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:24:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/13 10:25:44 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
        game->north.img = mlx_xpm_file_to_image(game->mlx, game->north.path,
			&game->north.width, &game->north.height);
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->south.path,
			&game->south.width, &game->south.height);
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->east.path,
			&game->east.width, &game->east.height);
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->west.path,
			&game->west.width, &game->west.height);
}

// void init_rgb(t_game *game)
// {
//         game->floor.color = create_trgb(0, game->floor.r, game->floor.g, game->floor.b);
//         game->ceiling.color = create_trgb(0, game->ceiling.r, game->ceiling.g, game->ceiling.b);
// }