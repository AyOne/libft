/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:49:33 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 01:55:40 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	tmp;

	start = str;
	end = str + ft_strlen(str) - 1;
	while (end > start)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	buffer[14];
	size_t	i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		buffer[i++] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		buffer[i++] = '0';
	while (nbr > 0)
	{
		buffer[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	buffer[i] = '\0';
	ft_putstr_fd(ft_strrev(buffer), fd);
}
