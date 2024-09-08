/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:02:58 by gbetting          #+#    #+#             */
/*   Updated: 2024/09/09 00:08:58 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// https://www.geeksforgeeks.org/quick-sort-algorithm/

static void	swap(int64_t *a, int64_t *b)
{
	int64_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int64_t *array, int64_t low, int64_t high)
{
	int64_t	pivot;
	int64_t	i;
	int64_t	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (array[j] < pivot)
			swap(&array[++i], &array[j]);
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quicksort(int64_t *array, int64_t low, int64_t high)
{
	int64_t	pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

void	ft_qsort(int64_t *array, size_t size)
{
	quicksort(array, 0, size - 1);
}
