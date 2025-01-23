/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsolucas <imsolucas@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:16:47 by imsolucas         #+#    #+#             */
/*   Updated: 2025/01/07 13:15:15 by imsolucas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ',');
}

static int	count_string(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && check_whitespace(*str))
			str++;
		if (*str)
			count++;
		while (*str && !check_whitespace(*str))
			str++;
	}
	return (count);
}

static int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !check_whitespace(str[i]))
		i++;
	return (i);
}

static char	*print_word(char *str)
{
	int		len;
	int		i;
	char	*word;

	len = ft_len(str);
	i = 0;
	word = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_whitespace(char *str)
{
	char	**split;
	int		i;

	split = (char **)malloc((count_string(str) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && check_whitespace(*str))
			str++;
		if (*str)
		{
			split[i] = print_word(str);
			i++;
		}
		while (*str && !check_whitespace(*str))
			str++;
	}
	split[i] = NULL;
	return (split);
}
