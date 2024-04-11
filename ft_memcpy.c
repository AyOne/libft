/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:06:02 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 05:09:29 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*l_dst;
	unsigned long	*l_src;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	if (!dst && !src)
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
	{
		*c_dst++ = *c_src++;
	}
	return (dst);
}
