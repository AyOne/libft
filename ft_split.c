/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:12:17 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 02:45:27 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**strs;

	i = 0;
	j = 0;
	strs = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while (s[i + k] != c && s[i + k])
				k++;
			strs[j] = ft_substr(s, i, k);
			if (!strs[j++])
				return (free_strs(strs), NULL);
			i += k - 1;
		}
		i++;
	}
	return (strs);
}
