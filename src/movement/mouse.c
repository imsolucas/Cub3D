/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:43:32 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 15:03:59 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    center_mouse(t_game *game)
{
    mlx_mouse_move(game->mlx, game->win, MOUSE_CENTER_X, MOUSE_CENTER_Y);
}

int    handle_mouse(int x, int y, t_game *game)
{
    double rotation;
    double old_dir_x;
    double old_plane_x;

    (void)y;  // We only use horizontal mouse movement for rotation
    
    if (x == MOUSE_CENTER_X)
        return (0);
        
    // Calculate rotation based on mouse movement from center
    rotation = (x - MOUSE_CENTER_X) * MOUSE_SENSITIVITY;
    
    // Save old values for calculation
    old_dir_x = game->player.dir_x;
    old_plane_x = game->player.plane_x;
    
    // Rotate direction vector
    game->player.dir_x = game->player.dir_x * cos(rotation) - 
        game->player.dir_y * sin(rotation);
    game->player.dir_y = old_dir_x * sin(rotation) + 
        game->player.dir_y * cos(rotation);
    
    // Rotate camera plane
    game->player.plane_x = game->player.plane_x * cos(rotation) - 
        game->player.plane_y * sin(rotation);
    game->player.plane_y = old_plane_x * sin(rotation) + 
        game->player.plane_y * cos(rotation);
    
    // Reset mouse position to center
    center_mouse(game);
    
    return (0);
}