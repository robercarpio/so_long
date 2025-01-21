/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:10:31 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/28 13:58:23 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcontains(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;

	e = (ft_strlen(s1) - 1);
	s = 0;
	while (ft_strcontains(s1[s], set))
		s++;
	while (ft_strcontains(s1[e], set))
		e--;
	return (ft_substr(s1, s, (e - s) + 1));
}
