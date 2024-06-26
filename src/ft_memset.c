/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:53:20 by gbetting          #+#    #+#             */
/*   Updated: 2024/06/26 05:30:17 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, char c, size_t len)
{
	unsigned char	*c_ptr;
	unsigned long	*l_ptr;
	unsigned long	l;

	l = 0x101010101010101 * c;
	l_ptr = (unsigned long *)b;
	while (len >= sizeof(unsigned long))
	{
		*l_ptr = l;
		l_ptr++;
		len -= sizeof(unsigned long);
	}
	c_ptr = (unsigned char *)l_ptr;
	while (len--)
		*c_ptr++ = c;
	return (b);
}
