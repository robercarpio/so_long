/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:09:31 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/26 18:09:32 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	fill_cross(char **map, int y, int x)
{
	return (fill_left(map, y, x) || fill_right(map, y, x)
		|| fill_up(map, y, x) || fill_down(map, y, x));
}
