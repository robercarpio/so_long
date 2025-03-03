/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:01:18 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/27 18:01:45 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_update_storage(char *storage, char *buffer)
{
	char	*temp;

	if (!storage)
		storage = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(storage, buffer);
		if (!temp)
		{
			free(storage);
			return (NULL);
		}
		free(storage);
		storage = temp;
	}
	return (storage);
}
