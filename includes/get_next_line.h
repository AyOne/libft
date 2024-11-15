/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:31:48 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 01:44:11 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_fdbuffer
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	size_t	buffer_size;
	bool	eof;
}			t_fdbuffer;

char		*get_next_line(int fd);
char		*extract_line(t_fdbuffer *buf, size_t *line_size);
char		*read_file(t_fdbuffer *buf, size_t *line_size);
t_fdbuffer	*get_fdbuffer(int fd, t_dlist *lst);
void		free_fdbuffer(int fd, t_dlist *lst);
void		ft_gnl_destructor(void) __attribute__((destructor));

#endif