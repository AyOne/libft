/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:26:20 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:32:27 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlstpop_front(t_dlist *lst)
{
	t_dlist_node	*tmp;
	void			*content;

	if (!lst || !lst->head)
		return (NULL);
	tmp = lst->head;
	content = tmp->content;
	lst->head = tmp->next;
	if (lst->head)
		lst->head->prev = NULL;
	else
		lst->tail = NULL;
	free(tmp);
	lst->size--;
	return (content);
}

void	*ft_dlstpop_back(t_dlist *lst)
{
	t_dlist_node	*tmp;
	void			*content;

	if (!lst || !lst->tail)
		return (NULL);
	tmp = lst->tail;
	content = tmp->content;
	lst->tail = tmp->prev;
	if (lst->tail)
		lst->tail->next = NULL;
	else
		lst->head = NULL;
	free(tmp);
	lst->size--;
	return (content);
}

static t_dlist_node	*ft_dlstget_at(t_dlist *lst, size_t index)
{
	t_dlist_node	*tmp;

	if (index > lst->size / 2)
	{
		tmp = lst->tail;
		index = lst->size - index - 1;
		while (index--)
			tmp = tmp->prev;
		return (tmp);
	}
	tmp = lst->head;
	while (index--)
		tmp = tmp->next;
	return (tmp);
}

void	*ft_dlstpop_at(t_dlist *lst, size_t index)
{
	t_dlist_node	*tmp;
	void			*content;

	if (!lst || index >= lst->size)
		return (NULL);
	tmp = ft_dlstget_at(lst, index);
	content = tmp->content;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		lst->head = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	else
		lst->tail = tmp->prev;
	free(tmp);
	lst->size--;
	return (content);
}
