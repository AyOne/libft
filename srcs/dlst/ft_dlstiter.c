/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:00:22 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:42:24 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dlistdelone(t_dlist_node *node)
{
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
}

void	ft_dlstiter_from(t_dlist *lst, t_iterfunc f, size_t index, void *args)
{
	t_dlist_node	*tmp;
	t_dlist_node	*next;
	t_dlist_rtrn	ret;

	if (!lst || !f)
		return ;
	tmp = lst->head;
	while (tmp)
	{
		next = tmp->next;
		ret = f(tmp->content, index, args);
		if (ret & DLIST_DELETE)
		{
			ft_dlistdelone(tmp);
			lst->size--;
		}
		if (ret & DLIST_BREAK)
			break ;
		tmp = next;
		index++;
	}
}

void	ft_dlstiter(t_dlist *lst, t_iterfunc f, void *args)
{
	t_dlist_node	*tmp;
	t_dlist_node	*next;
	t_dlist_rtrn	ret;
	size_t			index;

	if (!lst || !f)
		return ;
	tmp = lst->head;
	index = 0;
	while (tmp)
	{
		next = tmp->next;
		ret = f(tmp->content, index, args);
		if (ret & DLIST_DELETE)
		{
			ft_dlistdelone(tmp);
			lst->size--;
		}
		if (ret & DLIST_BREAK)
			break ;
		tmp = next;
		index++;
	}
}
