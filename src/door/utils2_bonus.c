/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:40:09 by abinti-a          #+#    #+#             */
/*   Updated: 2025/02/12 09:40:28 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static bool	is_valid_map_line(char *line)
{
	while (*line && *line != '\n')
	{
		if (!ft_strchr(" 01NSEWD", *line))
			return (false);
		line++;
	}
	return (true);
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
