/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:24:45 by abinti-a          #+#    #+#             */
/*   Updated: 2025/01/21 14:25:36 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->north.path,
			&game->north.width, &game->north.height);
	if (!game->north.img)
		error_exit("Failed to load North texture");
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->south.path,
			&game->south.width, &game->south.height);
	if (!game->south.img)
		error_exit("Failed to load South texture");
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->east.path,
			&game->east.width, &game->east.height);
	if (!game->east.img)
		error_exit("Failed to load East texture");
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->west.path,
			&game->west.width, &game->west.height);
	if (!game->west.img)
		error_exit("Failed to load West texture");
}
