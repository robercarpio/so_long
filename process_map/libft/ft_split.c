/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:41:10 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/02 18:20:12 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_countwords(char const *str, int c)
{
	size_t	i;
	int		b;

	b = 0;
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			if (b == 0)
			{
				i++;
				b = 1;
			}
		}
		else
		{
			b = 0;
		}
		str++;
	}
	return (i);
}

static char	**ft_free(int i, char **arr)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **arr)
{
	int	i;
	int	start;
	int	pos;

	i = 0;
	pos = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				arr[pos] = ft_substr(s, start, i - start);
				if (!arr[pos])
					return (ft_free(pos, arr));
				pos++;
			}
		}
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**arr;

	words = ft_countwords(s, c);
	arr = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_fill(s, c, arr));
}
