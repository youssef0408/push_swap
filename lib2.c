/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:17:55 by yothmani          #+#    #+#             */
/*   Updated: 2023/08/30 19:05:58 by yothmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*ft_cut_str(const char *str, char c)
{
	int		i;
	int		word_len;
	char	*new;

	i = 0;
	word_len = 0;
	while (str[i] == c)
		i++;
	while (str[i + word_len] != c && str[i + word_len] != '\0')
		word_len++;
	new = malloc(sizeof(char) * (word_len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tab[i] = ft_cut_str(s, c);
			if (!tab[i])
				return (ft_free(tab, i - 1));
			i++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
