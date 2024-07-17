/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 03:45:54 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 03:53:53 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstadd_back(t_dlist *lst, void *new)
{
	t_dlist_node	*new_node;
	t_dlist_node	*last;

	if (!lst)
		return (NULL);
	new_node = malloc(sizeof(t_dlist_node));
	if (!new_node)
		return (NULL);
	new_node->content = new;
	new_node->next = NULL;
	if (!lst->tail)
	{
		lst->tail = new_node;
		lst->head = new_node;
	}
	else
	{
		last = lst->tail;
		last->next = new_node;
		new_node->prev = last;
		lst->tail = new_node;
	}
	lst->size++;
	return (lst);
}
