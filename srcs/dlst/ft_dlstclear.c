/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 03:53:07 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:22:37 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist *lst, void (*del)(void *))
{
	t_dlist_node	*tmp;
	t_dlist_node	*next;

	if (!lst)
		return ;
	tmp = lst->head;
	while (tmp)
	{
		next = tmp->next;
		if (del)
			del(tmp->content);
		free(tmp);
		tmp = next;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void	ft_dlstfree(t_dlist *lst, void (*del)(void *))
{
	ft_dlstclear(lst, del);
	free(lst);
}
