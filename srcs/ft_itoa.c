/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:30:10 by gbetting          #+#    #+#             */
/*   Updated: 2024/06/26 05:28:42 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int32_t n)
{
	size_t			len;
	uint32_t		nb;

	len = 0;
	if (n <= 0)
	{
		len++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int32_t n)
{
	size_t	len;
	char	*str;
	int8_t	sign;

	len = ft_numlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	while (len > 0 && str[len - 1] != '-')
	{
		str[--len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
