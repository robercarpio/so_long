/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:44:41 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/28 12:38:06 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*pts;
	size_t				i;
	size_t				b;

	b = 0;
	i = 0;
	pts = s;
	while (i < n && b == 0)
	{
		if (*pts != (unsigned char)c)
		{
			pts++;
			i++;
		}
		else
			b = 1;
	}
	if (b == 0)
	{
		return (NULL);
	}
	return ((void *)pts);
}
