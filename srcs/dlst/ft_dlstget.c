/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:11:27 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:35:17 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline size_t	ft_dlstsize(t_dlist *lst)
{
	if (!lst)
		return (0);
	return (lst->size);
}

void	*ft_dlstget(t_dlist *lst, size_t index)
{
	t_dlist_node	*tmp;

	if (!lst || index >= lst->size)
		return (NULL);
	if (index > lst->size / 2)
	{
		tmp = lst->tail;
		index = lst->size - index - 1;
		while (index--)
			tmp = tmp->prev;
		return (tmp->content);
	}
	tmp = lst->head;
	while (index--)
		tmp = tmp->next;
	return (tmp->content);
}

void	*ft_dlstfirst(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	return (lst->head->content);
}

void	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	return (lst->tail->content);
}
