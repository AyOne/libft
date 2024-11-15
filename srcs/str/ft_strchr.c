/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:33:19 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/15 02:07:34 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnchr(const char *s, char c, size_t size)
{
	size_t	i;

	i = 0;
	while (s && i < size && s[i])
	{
		if (s[i++] == c)
			return ((char *)s + i - 1);
	}
	return (NULL);
}
