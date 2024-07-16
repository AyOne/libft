/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:20:22 by gbetting          #+#    #+#             */
/*   Updated: 2024/06/28 04:21:34 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memdupcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*l_dst;
	unsigned long	*l_src;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (!dst)
		dst = malloc(n);
	if (!dst)
		return (NULL);
	l_dst = (unsigned long *)dst;
	l_src = (unsigned long *)src;
	while (n >= sizeof(unsigned long))
	{
		*l_dst++ = *l_src++;
		n -= sizeof(unsigned long);
	}
	c_dst = (unsigned char *)l_dst;
	c_src = (unsigned char *)l_src;
	while (n--)
		*c_dst++ = *c_src++;
	return (dst);
}

void	ft_lstfree(t_list **lst, bool entire_lst, t_list *prev)
{
	t_list	*tmp;

	if (entire_lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
		return ;
	}
	free((*lst)->content);
	tmp = *lst;
	if (prev)
		prev->next = (*lst)->next;
	else
		tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
}

t_list	*ft_lstaddnew(t_list **lst, void *content, size_t size)
{
	t_list	*new;
	t_list	*last;

	if (!*lst)
	{
		*lst = malloc(sizeof(t_list));
		if (!(*lst))
			return (NULL);
		(*lst)->content = content;
		(*lst)->content_size = size;
		(*lst)->next = NULL;
		return (*lst);
	}
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->content_size = size;
	new->next = NULL;
	last = *lst;
	while (last && last->next)
		last = last->next;
	last->next = new;
	return (new);
}

t_fdbuffer	*get_fdbuffer(int fd, t_list **lst)
{
	t_list	*node;

	if (*lst)
	{
		node = *lst;
		while (node)
		{
			if (((t_fdbuffer *)node->content)->fd == fd)
				return (node->content);
			node = node->next;
		}
	}
	node = ft_lstaddnew(lst, NULL, 0);
	if (!node)
		return (NULL);
	node->content = malloc(sizeof(t_fdbuffer));
	if (!node->content)
		return (ft_lstfree(lst, true, NULL), NULL);
	((t_fdbuffer *)node->content)->fd = fd;
	((t_fdbuffer *)node->content)->buffer_size = 0;
	((t_fdbuffer *)node->content)->eof = false;
	return (node->content);
}

void	ft_fdlstfree(int fd, t_list **lst)
{
	t_list	*prev;
	t_list	*head;
	t_list	*tmp;

	prev = NULL;
	head = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (((t_fdbuffer *)(*lst)->content)->fd == fd)
		{
			if (head == *lst)
				head = tmp;
			ft_lstfree(lst, false, prev);
			break ;
		}
		else
			prev = *lst;
		*lst = tmp;
	}
	*lst = head;
}
