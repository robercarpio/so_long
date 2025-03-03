/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:43 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 19:43:26 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_MAP_H
# define PRINT_MAP_H

# include "../events/events.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../so_long.h"
# include "../gnl/get_next_line.h"
# include "../aux/aux.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

void	play(char *route);
void	init_structs(t_map *map, t_player *player, t_game *game, char *route);
void	print_chunk(int x, int y, char chunk, t_game *game);
void	print_map(t_game game);
void	validate_map(char *full_route, t_game *game, t_map *map);
int		is_map_playable(char *full_route, t_game *game);
void	init_game_struct(t_game *game, t_map *map, t_player *player);
void	init_map_struct(t_map *map, t_player *player, char *route);
#endif	