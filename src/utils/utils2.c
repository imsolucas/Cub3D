/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:58:05 by imsolucas         #+#    #+#             */
/*   Updated: 2025/02/12 13:20:49 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW", line[i]))
		{
			ft_putstr_fd("Error\nInvalid character '", 2);
			ft_putchar_fd(line[i], 2);
			ft_putendl_fd("' in map. Only ' 01NSEW' are allowed.", 2);
			exit(1);
		}
		i++;
	}
	return (true);
}

static int	check_texture_type(char *elem)
{
	if (!ft_strncmp(elem, "NO", 2) || !ft_strncmp(elem, "SO", 2)
		|| !ft_strncmp(elem, "WE", 2) || !ft_strncmp(elem, "EA", 2))
		return (TYPE_TEXTURE);
	return (TYPE_ERROR);
}

static int	check_element_type(char **split)
{
	int	type;

	type = TYPE_ERROR;
	if (!split[0])
		return (TYPE_ERROR);
	if (ft_strlen(split[0]) == 2)
		type = check_texture_type(split[0]);
	else if (ft_strlen(split[0]) == 1)
	{
		if (split[0][0] == 'F' || split[0][0] == 'C')
			type = TYPE_COLOR;
	}
	return (type);
}

int	element_type(char *line)
{
	char	**split;
	int		type;

	if (!line || !*line)
		return (TYPE_EMPTY);
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (TYPE_EMPTY);
	if (*line == '1' || *line == ' ' || *line == '0')
	{
		if (!is_valid_map_line(line))
			return (TYPE_ERROR);
		return (TYPE_MAP);
	}
	split = ft_split(line, ' ');
	if (!split)
		return (TYPE_ERROR);
	type = check_element_type(split);
	free_split(split);
	return (type);
}
