/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:12:00 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/09/28 18:46:13 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptdest;
	const unsigned char	*ptsrc;
	size_t				i;

	ptdest = dest;
	ptsrc = src ;
	i = 0;
	if (!ptdest && !ptsrc)
		return (NULL);
	while (i < n)
	{
		ptdest[i] = ptsrc[i];
		i++;
	}
	return (dest);
}
