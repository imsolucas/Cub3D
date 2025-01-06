/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:22:26 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:32:00 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*newnode;
	t_node	*prevnode;

	if (!lst || !del)
		return ;
	prevnode = 0;
	newnode = *lst;
	while (newnode != 0)
	{
		prevnode = newnode;
		newnode = newnode -> next;
		del(prevnode -> content);
		free(prevnode);
	}
	*lst = newnode;
}
