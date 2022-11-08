/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:38:28 by greita            #+#    #+#             */
/*   Updated: 2021/12/09 09:56:43 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_charscount(char const *s, char c, size_t i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static size_t	ft_wordscount(const char *s, char c)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static char	**ft_arrfree(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_wordscount(s, c) + 1));
	if (!arr)
		return (NULL);
	i = ft_charscount(s, c, i);
	while (j < ft_wordscount(s, c) && s[i])
	{
		arr[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
		if (!arr[j])
			return (ft_arrfree(&arr[j]));
		i += ft_wordlen(&s[i], c);
		j++;
		i = ft_charscount(s, c, i);
	}
	arr[j] = NULL;
	return (arr);
}
