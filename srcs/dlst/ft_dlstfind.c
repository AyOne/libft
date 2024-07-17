/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:26:06 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:37:49 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dlstfind(t_dlist *lst, void *content,
	t_cmpfunc cmp)
{
	t_dlist_node	*tmp;

	if (!lst || !cmp)
		return (NULL);
	tmp = lst->head;
	while (tmp)
	{
		if (cmp(tmp->content, content) == 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}
