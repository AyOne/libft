/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:37:03 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 00:38:07 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	*s1_l;
	unsigned long	*s2_l;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_l = (unsigned long *)s1;
	s2_l = (unsigned long *)s2;
	while (n >= sizeof(unsigned long))
	{
		if (*s1_l != *s2_l)
			break ;
		s1_l++;
		s2_l++;
		n -= sizeof(unsigned long);
	}
	s1_c = (unsigned char *)s1_l;
	s2_c = (unsigned char *)s2_l;
	while (n--)
	{
		if (*s1_c != *s2_c)
			return (*s1_c - *s2_c);
		s1_c++;
		s2_c++;
	}
	return (0);
}
