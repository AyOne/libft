/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:38:30 by gbetting          #+#    #+#             */
/*   Updated: 2024/11/10 22:40:47 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int32_t n)
{
	return (ft_strdup(ft_itoa_nm(n)));
}

char	*ft_ltoa(int64_t n)
{
	return (ft_strdup(ft_ltoa_nm(n)));
}

char	*ft_uitoa(uint32_t n)
{
	return (ft_strdup(ft_uitoa_nm(n)));
}

char	*ft_ultoa(uint64_t n)
{
	return (ft_strdup(ft_ultoa_nm(n)));
}
