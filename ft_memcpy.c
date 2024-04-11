/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:06:02 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 00:46:50 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*l_dst;

	l_dst = (unsigned long *)dst;
	while (n >= sizeof(unsigned long))
	{
		*l_dst = *(unsigned long *)src;
		l_dst++;
		src += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	while (n--)
	{
		*(unsigned char *)l_dst = *(unsigned char *)src;
		l_dst++;
		src++;
	}
	return (dst);
}
