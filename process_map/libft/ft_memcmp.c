/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:54:25 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/26 19:19:54 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt1;
	const unsigned char	*pt2;
	size_t				i;

	pt1 = s1;
	pt2 = s2;
	i = 0;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
		{
			return (pt1[i] - pt2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return (pt1[i] - pt2[i]);
	}
	return (0);
}
