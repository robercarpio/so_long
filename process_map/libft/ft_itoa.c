/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:45:13 by rcarpio-          #+#    #+#             */
/*   Updated: 2024/10/03 15:45:15 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_r_minzero(int n, char *str)
{
	free(str);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	return (0);
}

int	ft_nlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	m;
	int		d;

	d = ft_nlen(n);
	str = (char *)malloc(d + 1);
	if (!str)
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (ft_r_minzero(n, str));
	m = n;
	if (n < 0)
		m = -n;
	str[d] = '\0';
	while (d--)
	{
		str[d] = (m % 10) + 48;
		m = m / 10;
	}
	if (n < 0)
		str [0] = '-';
	return (str);
}
