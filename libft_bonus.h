/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:43:57 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 15:47:47 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief The lstnew() function allocates and returns a new element. The
 * variable 'content' is initialized with the value of the parameter 'content'.
 * The variable 'next' is initialized to NULL.
 * @param content The content to create the new element with.
 * @return The lstnew() function returns the new element.
*/
t_list	*ft_lstnew(void *content);
/**
 * @brief The lstadd_front() function adds the element 'new' at the beginning of
 * the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief The lstsize() function counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The lstsize() function returns the number of elements in the list.
*/
int		ft_lstsize(t_list *lst);
/**
 * @brief The lstlast() function returns the last element of the list.
 * @param lst The beginning of the list.
 * @return The lstlast() function returns the last element of the list.
*/
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief The lstadd_back() function adds the element 'new' at the end of the
 * list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief The lstdelone() function takes as a parameter an element and frees the
 * memory of the element's content using the function 'del' given as a parameter
 * and free the element. The memory of 'next' must not be freed.
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief The lstdel() function takes as a parameter the address of a pointer to
 * an element and frees the memory of this element and all its successors using
 * the function 'del' and free(). Finally, the pointer must be set to NULL.
 * @param lst The address of a pointer to the first link of a list.
 * @param del The address of the function used to delete the content.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief The lstiter() function iterates the list 'lst' and applies the
 * function 'f' to the content of each element.
 * @param lst The beginning of the list.
 * @param f The address of the function to apply.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief The lstmap() function iterates the list 'lst' and applies the function
 * 'f' to the content of each element. Creates a new list resulting of the
 * successive applications of the function 'f'. The 'del' function is used to
 * delete the content of an element if needed.
 * @param lst The beginning of the list.
 * @param f The address of the function to apply.
 * @param del The address of the function used to delete the content.
 * @return The lstmap() function returns the new list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
