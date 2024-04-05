/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbraud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:24:00 by tbraud            #+#    #+#             */
/*   Updated: 2023/11/13 11:24:02 by tbraud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_free_all(size_t i, char **tab)
{
	while (i != 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static size_t	ft_malloc_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

static size_t	ft_word_size(char const *s, char c, size_t j)
{
	size_t	i;

	i = j;
	while (s[i])
	{
		if (s[i] == c)
			return (i - j);
		i++;
	}
	return (i - j);
}

static char	**ft_make_split(char const *s, char c, char **tab, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	while (i < size)
	{
		x = 0;
		while (s[j] && s[j] == c)
			j++;
		tab[i] = malloc(sizeof(char) * (ft_word_size(s, c, j) + 1));
		if (!tab)
			return (ft_free_all(i, tab));
		while (s[j] && s[j] != c)
		{
			tab[i][x] = s[j];
			x++;
			j++;
		}
		tab[i][x] = 0;
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size_malloc;

	if (!s)
		return (0);
	size_malloc = ft_malloc_size(s, c);
	tab = malloc (sizeof(char *) * (size_malloc + 1));
	if (!tab)
		return (0);
	if (ft_make_split(s, c, tab, size_malloc) == 0)
		return (0);
	tab[size_malloc] = 0;
	return (tab);
}
