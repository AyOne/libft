/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 05:44:29 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/03 02:12:08 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t	ft_min(int64_t a, int64_t b)
{
	if (a < b)
		return (a);
	return (b);
}

int64_t	ft_max(int64_t a, int64_t b)
{
	if (a > b)
		return (a);
	return (b);
}

uint64_t	ft_minu(uint64_t a, uint64_t b)
{
	if (a < b)
		return (a);
	return (b);
}

uint64_t	ft_maxu(uint64_t a, uint64_t b)
{
	if (a > b)
		return (a);
	return (b);
}
