/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:29:15 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:32:00 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	t_node	*newnode;

	newnode = lst;
	while (newnode != 0)
	{
		f(newnode -> content);
		newnode = newnode -> next;
	}
}
