/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_nm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:30:10 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/10 23:52:27 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_nm(int32_t n)
{
	static char		str[12];
	size_t			len;
	int8_t			sign;

	sign = 1;
	len = 10;
	if (n < 0)
		sign = -1;
	while (n * sign > 0 || len == 10)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[len--] = '-';
	return (str + len + 1);
}

char	*ft_ltoa_nm(int64_t n)
{
	static char		str[21];
	size_t			len;
	int8_t			sign;

	sign = 1;
	len = 19;
	str[len] = '0';
	if (n < 0)
		sign = -1;
	while (n * sign > 0 || len == 19)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[len--] = '-';
	return (str + len + 1);
}

char	*ft_uitoa_nm(uint32_t n)
{
	static char		str[11];
	size_t			len;

	len = 9;
	while (n > 0 || len == 9)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str + len + 1);
}

char	*ft_ultoa_nm(uint64_t n)
{
	static char		str[21];
	size_t			len;

	len = 19;
	while (n > 0 || len == 19)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str + len + 1);
}
