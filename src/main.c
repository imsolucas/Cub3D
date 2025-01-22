/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:49:52 by imsolucas         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/21 17:42:32 by imsolucas        ###   ########.fr       */
=======
/*   Updated: 2025/01/21 13:10:21 by abinti-a         ###   ########.fr       */
>>>>>>> feat/raycasting
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static bool is_valid_file(char *file)
{
    int len = ft_strlen(file);
    
    if (len < 5)  // Minimum length for ".cub"
        return (false);
    if (ft_strcmp(file + len - 4, ".cub") != 0)
        return (false);
    // Check if file exists and is readable
    int fd = open(file, O_RDONLY);
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
	parse(argv[1], game);
	init_mlx(game);
	mlx_loop(game->mlx);
	cleanup(game);
    return (0);
}

