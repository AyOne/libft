/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:53:42 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/16 23:05:45 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen_r(uint64_t nbr, char *base, size_t len)
{
	if (nbr == 0)
		return (1);
	return (1 + ft_nbrlen_r(nbr / len, base, len));
}

size_t	ft_nbrlen(uint64_t nbr, char *base)
{
	return (ft_nbrlen_r(nbr, base, ft_strlen(base)));
}
