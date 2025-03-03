/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:34 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/02/27 18:24:49 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"

// void	init_structs(t_map *map, t_player *player, t_game *game, char *route)
// {
// 	char	**a_map;

// 	a_map = allocate_map(route);
// 	player->px = pos_x(a_map);
// 	player->py = pos_y(a_map);
// 	player->moves = 0;
// 	player->collectibles_taken = 0;
// 	map->n_collectibles = collectible_count(a_map);
// 	map->size_x = line_len(a_map[0]);
// 	map->size_y = map_height(a_map);
// 	map->player = *player;
// 	map->alloc = a_map;
// 	map->px_exit = coord_x(a_map, 'E');
// 	map->py_exit = coord_y(a_map, 'E');
// 	game->mlx = mlx_init();
// 	game->player = *player;
// 	game->map = *map;
// 	game->pixels = 50;
// 	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
// 			&game->pixels, &game->pixels);
// 	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
// 			&game->pixels, &game->pixels);
// 	game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
// 			&game->pixels, &game->pixels);
// 	game->character = mlx_xpm_file_to_image(game->mlx,
// 			"./textures/character.xpm", &game->pixels, &game->pixels);
// 	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
// 			&game->pixels, &game->pixels);
// }

void	init_map_struct(t_map *map, t_player *player, char *route)
{
	char	**a_map;

	a_map = allocate_map(route);
	player->px = pos_x(a_map);
	player->py = pos_y(a_map);
	player->moves = 0;
	player->collectibles_taken = 0;
	map->n_collectibles = collectible_count(a_map);
	map->size_x = line_len(a_map[0]);
	map->size_y = map_height(a_map);
	map->player = *player;
	map->alloc = a_map;
	map->px_exit = coord_x(a_map, 'E');
	map->py_exit = coord_y(a_map, 'E');
}

void	init_game_struct(t_game *game, t_map *map, t_player *player)
{
	game->mlx = mlx_init();
	game->player = *player;
	game->map = *map;
	game->pixels = 50;
	game->floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&game->pixels, &game->pixels);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->pixels, &game->pixels);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/coin.xpm",
			&game->pixels, &game->pixels);
	game->character = mlx_xpm_file_to_image(game->mlx,
			"./textures/character.xpm", &game->pixels, &game->pixels);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->pixels, &game->pixels);
}

void	init_structs(t_map *map, t_player *player, t_game *game, char *route)
{
	init_map_struct(map, player, route);
	init_game_struct(game, map, player);
}
