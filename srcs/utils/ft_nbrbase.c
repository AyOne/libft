/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:52:07 by gbetting          #+#    #+#             */
/*   Updated: 2024/07/16 22:52:06 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbrbase_nm(uint64_t nbr, char *base)
{
	static char	buffer[65];
	char		*ptr;
	size_t		len;

	ptr = &buffer[64];
	*ptr = '\0';
	len = ft_strlen(base);
	if (nbr == 0)
		*--ptr = base[0];
	while (nbr > 0)
	{
		*--ptr = base[nbr % len];
		nbr /= len;
	}
	return (ptr);
}

char	*ft_nbrbase(uint64_t nbr, char *base)
{
	char	*str;

	str = ft_strdup(ft_nbrbase_nm(nbr, base));
	return (str);
}
