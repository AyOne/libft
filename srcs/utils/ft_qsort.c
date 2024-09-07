/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 03:02:58 by gbetting          #+#    #+#             */
/*   Updated: 2024/09/07 03:19:05 by gbetting         ###   ########.fr       */
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

static int	partition(int64_t *array, int64_t low, int64_t high, t_cmpfunc cmp)
{
	int64_t	pivot;
	int64_t	i;
	int64_t	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if ((cmp == NULL && array[j] < pivot)
			|| (cmp != NULL && cmp(&array[j], &pivot) < 0))
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quicksort(int64_t *array, int64_t low, int64_t high, t_cmpfunc cmp)
{
	int64_t	pi;

	if (low < high)
	{
		pi = partition(array, low, high, cmp);
		quicksort(array, low, pi - 1, cmp);
		quicksort(array, pi + 1, high, cmp);
	}
}

void	ft_qsort(int64_t *array, size_t size)
{
	quicksort(array, 0, size - 1, NULL);
}

void	ft_qsort_cmp(int64_t *array, size_t size, t_cmpfunc cmp)
{
	quicksort(array, 0, size - 1, cmp);
}
