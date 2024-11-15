/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:25:07 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 03:27:38 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	ft_strnchr(const char *s, int c, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (s[i] == c)
			return (true);
	}
	return (false);
}

static char	*extract_line(t_fdbuffer *buf, size_t *line_size)
{
	size_t	i;
	char	*line;

	i = 0;
	*line_size = buf->buffer_size;
	while (i < buf->buffer_size && buf->buffer[i] != '\n' && buf->buffer[i])
		i++;
	if (!(buf->buffer_size > 0 && buf->buffer[i++] == '\n'))
		return (line = ft_memdupcpy(NULL, buf->buffer, *line_size), line);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memdupcpy(line, buf->buffer, i);
	line[i] = '\0';
	buf->buffer_size -= i;
	ft_memdupcpy(buf->buffer, buf->buffer + i, buf->buffer_size);
	buf->buffer[buf->buffer_size] = '\0';
	*line_size = i;
	return (line);
}

static char	*compile_line(t_list *lst, size_t *line_size)
{
	char	*line;
	t_list	*head;
	size_t	i;

	*line_size = 0;
	head = lst;
	while (lst)
	{
		*line_size += lst->content_size;
		lst = lst->next;
	}
	line = malloc(sizeof(char) * (*line_size + 1));
	if (!line)
		return (ft_lstfree(&head, true, NULL), NULL);
	i = 0;
	lst = head;
	while (lst)
	{
		ft_memdupcpy(line + i, lst->content, lst->content_size);
		i += lst->content_size;
		lst = lst->next;
	}
	line[*line_size] = '\0';
	return (ft_lstfree(&head, true, NULL), line);
}

static char	*read_file(t_fdbuffer *buf, size_t *line_size)
{
	ssize_t	read_bytes;
	t_list	*lst;
	char	*line;

	lst = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		line = extract_line(buf, line_size);
		if (!line)
			return (ft_lstfree(&lst, true, NULL), NULL);
		if (ft_lstaddnew(&lst, line, *line_size) == NULL || !lst)
			return (free(line), ft_lstfree(&lst, true, NULL), NULL);
		if (*line_size != 0 && line[*line_size - 1] == '\n')
			break ;
		read_bytes = read(buf->fd, buf->buffer, BUFFER_SIZE);
		buf->buffer_size = read_bytes;
		if (read_bytes <= 0)
			break ;
		buf->buffer[read_bytes] = '\0';
	}
	buf->eof = read_bytes <= 0;
	if (read_bytes < 0)
		return (ft_lstfree(&lst, true, NULL), NULL);
	return (compile_line(lst, line_size));
}

char	*get_next_line(int fd)
{
	static t_list		*lst = NULL;
	t_fdbuffer			*buf;
	char				*line;
	size_t				line_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = get_fdbuffer(fd, &lst);
	if (!buf)
		return (NULL);
	if (!buf->eof && !ft_strnchr(buf->buffer, '\n', buf->buffer_size))
		line = read_file(buf, &line_size);
	else
		line = extract_line(buf, &line_size);
	if (!line)
		return (ft_fdlstfree(fd, &lst), NULL);
	if (line_size == 0 && buf->eof)
		return (ft_fdlstfree(fd, &lst), free(line), NULL);
	return (line);
}

char		*gnl(int fd)__attribute__((alias("get_next_line")));
