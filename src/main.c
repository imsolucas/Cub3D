/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/23 14:15:57 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_file(char *file)
{
	int	len;
	int	fd;

	len = ft_strlen(file);
	if (len < 5)
		return (false);
	if (ft_strcmp(file + len - 4, ".cub") != 0)
		return (false);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || !is_valid_file(argv[1]))
	{
		printf("Error\nInvalid file\n");
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		printf("Error\nMalloc failed\n");
		exit(1);
	}
	init_struct(game);
	parse(argv[1], game);
	init_game(game);
	// mlx_hook(game->win, 2, 1L << 0, key_press, game);
	// mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_hook(game->win, 17, 0, cleanup, game);
	mlx_loop(game->mlx);
	return (0);
}
