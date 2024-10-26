/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:49:38 by gbetting          #+#    #+#             */
/*   Updated: 2024/10/26 08:56:40 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstadd_at(t_dlist *lst, void *content, size_t index)
{
	t_dlist_node	*new_node;
	t_dlist_node	*tmp;
	size_t			i;

	if (!lst || !content)
		return (NULL);
	if (index == 0)
		return (ft_dlstadd_front(lst, content));
	else if (index >= lst->size)
		return (ft_dlstadd_back(lst, content));
	new_node = malloc(sizeof(t_dlist_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	i = -1;
	tmp = lst->head;
	while (++i < index - 1)
		tmp = tmp->next;
	new_node->next = tmp->next;
	new_node->prev = tmp;
	tmp->next->prev = new_node;
	tmp->next = new_node;
	lst->size++;
	return (lst);
}
