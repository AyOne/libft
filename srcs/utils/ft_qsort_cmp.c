/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 04:25:29 by gbetting          #+#    #+#             */
/*   Updated: 2024/09/09 00:09:04 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.geeksforgeeks.org/quick-sort-algorithm/

#include "libft.h"

static void	swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(void **array, int64_t low, int64_t high, t_cmpfunc cmp)
{
	void	*pivot;
	int64_t	i;
	int64_t	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (cmp(array[j], pivot) < 0)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quicksort(void **array, int64_t low, int64_t high, t_cmpfunc cmp)
{
	int64_t	pi;

	if (low < high)
	{
		pi = partition(array, low, high, cmp);
		quicksort(array, low, pi - 1, cmp);
		quicksort(array, pi + 1, high, cmp);
	}
}

void	ft_qsort_cmp(void **array, size_t size, t_cmpfunc cmp)
{
	quicksort(array, 0, size - 1, cmp);
}
