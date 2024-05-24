/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:56:27 by gbetting          #+#    #+#             */
/*   Updated: 2024/05/24 14:44:44 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	long	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) - start;
	if (s_len <= 0 || len == 0)
		return (ft_strdup(""));
	if ((size_t)s_len > len)
		s_len = len;
	str = malloc(s_len + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, s_len);
	str[s_len] = '\0';
	return (str);
}
