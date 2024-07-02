/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:18:32 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/03 01:56:01 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct s_fdbuffer
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	size_t	buffer_size;
	bool	eof;
}				t_fdbuffer;

void		ft_lstfree(t_list **lst, bool entire_lst, t_list *prev);
t_list		*ft_lstaddnew(t_list **lst, void *content, size_t size);
void		*ft_memdupcpy(void *dst, const void *src, size_t n);
t_fdbuffer	*get_fdbuffer(int fd, t_list **lst);
void		ft_fdlstfree(int fd, t_list **lst);

char		*get_next_line(int fd);
#endif