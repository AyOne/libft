/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:30:10 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 05:28:06 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t			len;
	unsigned int	nb;

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
	while (len > 0 && str[len - 1] != '-')
	{
		str[--len] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}
