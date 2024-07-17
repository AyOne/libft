/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:08:48 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/17 04:41:30 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, t_applyfunc f, t_delfunc del)
{
	t_dlist			*new_lst;
	t_dlist_node	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_dlstnew();
	if (!new_lst)
		return (NULL);
	tmp = lst->head;
	while (tmp)
	{
		if (!ft_dlstadd_back(new_lst, f(tmp->content)))
			return (ft_dlstfree(new_lst, del), NULL);
		tmp = tmp->next;
	}
	return (new_lst);
}
