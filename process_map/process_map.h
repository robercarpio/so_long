/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:52 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 19:40:35 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_MAP_H
# define PROCESS_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../aux/aux.h"

void	consume_remaining(int fd, int *is_rect);
int		is_rectangle(char *route);
int		is_exit_reachable(char **grid, int y, int x);
int		check_map(char *route);
int		check_borders_map(char *route);
int		check_chars_allow(char *route);
int		are_coins_reachable(char **grid, int y, int x, int *i);
int		check_rectangle(int fd, int *len, int *rows);

#endif