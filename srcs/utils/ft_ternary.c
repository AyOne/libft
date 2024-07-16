/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 05:46:42 by gbetting          #+#    #+#             */
/*   Updated: 2024/06/26 05:48:41 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_t_int(bool condition, int64_t a, int64_t b)
{
	if (condition)
		return (a);
	return (b);
}

uint64_t	ft_t_uint(bool condition, uint64_t a, uint64_t b)
{
	if (condition)
		return (a);
	return (b);
}

double	ft_t_double(bool condition, double a, double b)
{
	if (condition)
		return (a);
	return (b);
}

void	*ft_t_ptr(bool condition, void *a, void *b)
{
	if (condition)
		return (a);
	return (b);
}
