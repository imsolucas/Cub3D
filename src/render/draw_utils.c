/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:00:12 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/03 16:45:15 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_hex(t_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->width + x * 4);
	return (*(unsigned int *)dst);
}
