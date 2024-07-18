/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:30:10 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/18 21:10:16 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	ft_numlen(int32_t n)
// {
// 	size_t			len;
// 	uint32_t		nb;

// 	len = 0;
// 	if (n <= 0)
// 	{
// 		len++;
// 		nb = -n;
// 	}
// 	else
// 		nb = n;
// 	while (nb > 0)
// 	{
// 		len++;
// 		nb /= 10;
// 	}
// 	return (len);
// }

char	*ft_itoa_nm(int64_t n)
{
	static char		str[21];
	size_t			len;
	int8_t			sign;

	sign = 1;
	len = 11;
	if (n < 0)
		sign = -1;
	while (len > 0)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		str[len] = '-';
	return (str + len);
}

// char	*ft_itoa(int32_t n)
// {
// 	size_t	len;
// 	char	*str;
// 	int8_t	sign;

// 	len = ft_numlen(n);
// 	str = ft_calloc(len + 1, sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	sign = 1;
// 	if (n < 0)
// 	{
// 		sign = -1;
// 		str[0] = '-';
// 	}
// 	while (len > 0 && str[len - 1] != '-')
// 	{
// 		str[--len] = n % 10 * sign + '0';
// 		n /= 10;
// 	}
// 	return (str);
// }

char	*ft_itoa(int64_t n)
{
	return (ft_strdup(ft_itoa_nm(n)));
}
