/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:00:49 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 01:43:48 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*compile_line(t_dlist *lst, size_t *line_size)
{
	char	*line;
	char	**arr;
	size_t	i;
	size_t	len;

	*line_size = 0;
	arr = (char **)ft_dlstto_array(lst);
	i = 0;
	while (arr[i])
	{
		*line_size += ft_strlen(arr[i]);
		i++;
	}
	line = ft_calloc(*line_size + 1, sizeof(char));
	if (!line)
		return (free(arr), ft_dlstfree(lst, free), NULL);
	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		ft_memcpy(line + i, arr[i], len);
		i += len;
	}
	return (free(arr), ft_dlstfree(lst, free), line);
}

char	*extract_line(t_fdbuffer *buf, size_t *line_size)
{
	size_t	i;
	char	*line;

	i = 0;
	*line_size = buf->buffer_size;
	while (i < buf->buffer_size && buf->buffer[i] && buf->buffer[i] != '\n')
		i++;
	if (!(buf->buffer_size > 0 && buf->buffer[i++] == '\n'))
		return (ft_memdup(buf->buffer, *line_size));
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, buf->buffer, i);
	buf->buffer_size -= i;
	ft_memcpy(buf->buffer, buf->buffer + i, buf->buffer_size);
	buf->buffer[buf->buffer_size] = '\0';
	*line_size = i;
	return (line);
}

char	*read_file(t_fdbuffer *buf, size_t *line_size)
{
	ssize_t	read_bytes;
	t_dlist	*lst;
	char	*line;

	lst = NULL;
	read_bytes = 1;
	while (read_bytes > 0)
	{
		line = extract_line(buf, line_size);
		if (!line)
			return (ft_dlstfree(lst, free), NULL);
		if (ft_dlstadd_back(lst, line) == NULL)
			return (free(line), ft_dlstfree(lst, free), NULL);
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
		return (ft_dlstfree(lst, free), NULL);
	return (compile_line(lst, line_size));
}

void	free_fdbuffer(int fd, t_dlist *lst)
{
	t_fdbuffer	**arr;
	size_t		i;
	size_t		target;

	arr = (t_fdbuffer **)ft_dlstto_array(lst);
	i = 0;
	target = 0;
	while (arr[i])
	{
		if (arr[i]->fd == fd)
		{
			target = i;
			break ;
		}
		i++;
	}
	free(arr);
	free(ft_dlstpop_at(lst, target));
}

t_fdbuffer	*get_fdbuffer(int fd, t_dlist *lst)
{
	t_fdbuffer	**arr;
	t_fdbuffer	*ret;
	size_t		i;

	arr = (t_fdbuffer **)ft_dlstto_array(lst);
	i = 0;
	while (arr[i])
	{
		if (arr[i]->fd == fd)
		{
			ret = arr[i];
			free(arr);
			return (ret);
		}
		i++;
	}
	free(arr);
	ret = ft_calloc(1, sizeof(t_fdbuffer));
	if (!ret)
		return (NULL);
	ret->fd = fd;
	ft_dlstadd_back(lst, ret);
	return (ret);
}
