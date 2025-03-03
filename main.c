/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:55 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 20:00:33 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include "./print_map/print_map.h"
#include "./events/events.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		play(argv[1]);
	else
		write(1, "Error: ./so_long map.ber\n", 24);
	return (0);
}
