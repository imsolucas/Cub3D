/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:04:22 by djin              #+#    #+#             */
/*   Updated: 2024/03/04 18:34:19 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *) s1);
	len2 = ft_strlen((char *) s2);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = s1[i];
	i = -1;
	while (++i < len2)
		join[len1 + i] = s2[i];
	join[len1 + i] = '\0';
	free((void *)s1);
	return (join);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("Hello", " There"));
// }
