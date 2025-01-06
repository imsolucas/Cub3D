/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:39:16 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:46:02 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*newnode;

	if (!lst || !new)
		return ;
	newnode = *lst;
	if (newnode != NULL)
	{
		newnode = ft_lstlast(newnode);
		newnode -> next = new;
		new -> prev = newnode;
	}
	else
		*lst = new;
}
