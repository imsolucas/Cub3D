/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:53 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 15:32:00 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*newnode;

	newnode = lst;
	while (newnode != NULL && newnode -> next != NULL)
		newnode = newnode -> next;
	return (newnode);
}
