/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:51:29 by gbetting          #+#    #+#             */
/*   Updated: 2025/03/18 16:02:44 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_if(int32_t condition, int32_t exit_code)
{
	if (condition)
		exit(exit_code);
}

void	ft_exit_if_null(void *ptr, int32_t exit_code)
{
	if (!ptr)
		exit(exit_code);
}

void	*ft_exit_if_fail_malloc(size_t size, int32_t exit_code)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(exit_code);
	return (ptr);
}

void	*ft_exit_if_fail_calloc(size_t nmemb, size_t size, int32_t exit_code)
{
	void	*ptr;

	ptr = calloc(nmemb, size);
	if (!ptr)
		exit(exit_code);
	return (ptr);
}
