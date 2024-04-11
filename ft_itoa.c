/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:30:10 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 01:30:30 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		sign;

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
	while (n != 0)
	{
		str[--len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
