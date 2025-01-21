/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:33:36 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/26 19:55:55 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = n;
	if (!d && !s)
		return (NULL);
	if (d > s && d < s + n)
		while (i--)
			d[i] = s[i];
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
