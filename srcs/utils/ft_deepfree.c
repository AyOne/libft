/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deepfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:21:50 by gbetting          #+#    #+#             */
/*   Updated: 2024/12/16 22:24:45 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deepfree(void **array, void (*del)(void *))
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	if (del)
	{
		while (array[i])
		{
			del(array[i]);
			free(array[i]);
			i++;
		}
	}
	free(array);
}
