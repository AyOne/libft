/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:12:17 by gbetting          #+#    #+#             */
/*   Updated: 2024/04/11 05:13:19 by gbetting         ###   ########.fr       */
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
	size_t	vars[3];
	char	**strs;

	if (!s)
		return (NULL);
	vars[0] = 0;
	vars[1] = 0;
	strs = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[vars[0]])
	{
		if (s[vars[0]] != c)
		{
			vars[2] = 0;
			while (s[vars[0] + vars[2]] != c && s[vars[0] + vars[2]])
				vars[2]++;
			strs[vars[1]] = ft_substr(s, vars[0], vars[2]);
			if (!strs[vars[1]++])
				return (free_strs(strs), NULL);
			vars[0] += vars[2] - 1;
		}
		vars[0]++;
	}
	return (strs);
}
