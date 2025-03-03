/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_remaining.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:15 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:09:17 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	consume_remaining(int fd, int *is_rect)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\0')
			*is_rect = 0;
		free(line);
		line = get_next_line(fd);
	}
}
