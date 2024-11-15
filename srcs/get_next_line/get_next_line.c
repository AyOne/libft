/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:30:45 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 01:42:50 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_dlist	*get_lst(bool is_destructor)
{
	static t_dlist	*lst = NULL;

	if (!lst && !is_destructor)
		lst = ft_dlstnew();
	return (lst);
}

char	*get_next_line(int fd)
{
	t_dlist		*lst;
	t_fdbuffer	*buf;
	char		*line;
	size_t		line_size;

	lst = get_lst(false);
	if (fd < 0 || BUFFER_SIZE < 1 || !lst)
		return (NULL);
	buf = get_fdbuffer(fd, lst);
	if (!buf)
		return (NULL);
	if (!buf->eof && ft_strnchr(buf->buffer, '\n', buf->buffer_size) == NULL)
		line = read_file(buf, &line_size);
	else
		line = extract_line(buf, &line_size);
	if (!line)
		return (free_fdbuffer(fd, lst), NULL);
	if (line_size == 0 && buf->eof)
		return (free_fdbuffer(fd, lst), free(line), NULL);
	return (line);
}

char	*gnl(int fd)__attribute__((alias("get_next_line")));

void	ft_gnl_destructor(void)
{
	ft_dlstfree(get_lst(true), free);
}
