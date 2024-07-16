/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 02:09:04 by gbetting          #+#    #+#             */
/*   Updated: 2024/05/30 14:26:50 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*buffer;

	if (!lst || !f)
		return (NULL);
	buffer = f(lst->content);
	new = ft_lstnew(buffer);
	if (!new)
		return (del(buffer), NULL);
	current = new;
	lst = lst->next;
	while (lst)
	{
		buffer = f(lst->content);
		current->next = ft_lstnew(buffer);
		if (!current->next)
			return (ft_lstclear(&new, del), del(buffer), NULL);
		current = current->next;
		lst = lst->next;
	}
	return (new);
}
