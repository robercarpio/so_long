/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:24 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 19:52:36 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../aux/aux.h"
# include "../so_long.h"
# include "../minilibx-linux/mlx.h"
# include "../print_map/print_map.h"

int		key_hook(int keycode, t_game *game);
int		can_move(t_game game, int c);
void	move(t_game *game, int keycode);
int		close_game(t_game *game);
void	free_map(char **map);
void	update_position(t_game *game, int x, int y);
int		x_game(t_game *game);
#endif