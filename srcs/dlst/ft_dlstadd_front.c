/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 03:50:57 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:22:33 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstadd_front(t_dlist *lst, void *new)
{
	t_dlist_node	*new_node;
	t_dlist_node	*first;

	if (!lst)
		return (NULL);
	new_node = malloc(sizeof(t_dlist_node));
	if (!new_node)
		return (NULL);
	new_node->content = new;
	new_node->prev = NULL;
	if (!lst->head)
	{
		lst->head = new_node;
		lst->tail = new_node;
	}
	else
	{
		first = lst->head;
		first->prev = new_node;
		new_node->next = first;
		lst->head = new_node;
	}
	lst->size++;
	return (lst);
}
