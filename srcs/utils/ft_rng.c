/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rng.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 01:59:28 by gbetting          #+#    #+#             */
/*   Updated: 2024/10/03 02:13:49 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static uint64_t	*ft_getseed(void)
{
	static uint64_t	seed;

	return (&seed);
}

void	ft_init_random(void)
{
	int		fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd < 0)
	{
		*ft_getseed() = (uint64_t) & ft_init_random;
		return ;
	}
	read(fd, ft_getseed(), sizeof(uint64_t));
}

inline void	ft_setseed(uint64_t seed)
{
	*ft_getseed() = seed;
}

int	ft_xorshift64(void)
{
	int64_t		x;

	x = *ft_getseed();
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	ft_setseed(x);
	return ((int)x);
}
