/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_chars_allowed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:54 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:09:55 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	only_chars_allowed(char *str, char *allow)
{
	int	i;
	int	b;

	while (*str)
	{
		b = 0;
		i = 0;
		while (allow[i] && b != 1)
		{
			if (*str == allow[i] || *str == '\n')
				b = 1;
			i++;
		}
		if (b == 0)
			return (0);
		str++;
	}
	return (b);
}
