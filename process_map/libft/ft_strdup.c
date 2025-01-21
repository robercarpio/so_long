/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:44:43 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/02 18:22:12 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc((ft_strlen(s) + 1));
	if (str != NULL)
	{
		ft_memcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	return (str);
}
