/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:02:05 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/28 11:37:28 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_d;
	size_t	l_s;
	size_t	s;

	l_s = 0;
	l_d = 0;
	while (dst[l_d] != '\0' && l_d < size)
		l_d++;
	while (src[l_s] != '\0')
		l_s++;
	if (size <= l_d)
		return (size + l_s);
	s = 0;
	while ((l_d + s) < (size - 1) && src[s] != 0)
	{
		dst[l_d + s] = src[s];
		s++;
	}
	dst[l_d + s] = '\0';
	return (l_s + l_d);
}
