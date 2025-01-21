/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:15:15 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/08 21:15:45 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*last;
	unsigned char	uc;

	last = NULL;
	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			last = s;
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return ((char *)last);
}
