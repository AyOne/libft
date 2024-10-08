/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstto_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:22:09 by gbetting          #+#    #+#             */
/*   Updated: 2024/08/16 22:58:48 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_dlstto_array(t_dlist *dlst)
{
	void			**array;
	t_dlist_node	*node;
	size_t			i;

	if (dlst == NULL)
		return (NULL);
	array = malloc(sizeof(void *) * (dlst->size + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	node = dlst->head;
	while (node != NULL)
	{
		array[i++] = node->content;
		node = node->next;
	}
	array[i] = NULL;
	return (array);
}

void	**ft_dlstto_array_free(t_dlist *dlst, void (*del)(void *))
{
	void	**ret;

	ret = ft_dlstto_array(dlst);
	ft_dlstclear(dlst, del);
	free(dlst);
	return (ret);
}
