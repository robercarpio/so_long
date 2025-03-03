/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:37 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 21:14:56 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_map.h"

int	is_map_playable(char *full_route, t_game *game)
{
	int		i;
	char	**e_map;
	char	**c_map;
	char	**chars_map;

	i = 0;
	e_map = allocate_map(full_route);
	c_map = allocate_map(full_route);
	are_coins_reachable(c_map, game->player.py, game->player.px, &i);
	if (i == game->map.n_collectibles
		&& is_exit_reachable(e_map, game->player.py, game->player.px))
	{
		chars_map = allocate_map(full_route);
		if (count_char(chars_map, 'P') == 1 && count_char(chars_map, 'E') == 1)
			return (free_map(e_map), free_map(c_map), free_map(chars_map), 1);
		else
		{
			print_error("Error: Solo puede haber una P y una E por mapa");
			close_game(game);
		}
	}
	free_map(e_map);
	free_map(c_map);
	close_game(game);
	return (0);
}

void	validate_map(char *full_route, t_game *game, t_map *map)
{
	if (check_map(full_route))
	{
		init_structs(map, &game->player, game, full_route);
		if (is_map_playable(full_route, game))
		{
			game->window = mlx_new_window(game->mlx, (map->size_x * 50),
					(map->size_y * 50), "so_long");
			print_map(*game);
			mlx_hook(game->window, 17, 0, close_game, game);
			mlx_key_hook(game->window, key_hook, game);
			mlx_loop(game->mlx);
		}
	}
	else
	{
		free(full_route);
		write(1, "Error: Mapa no válido\n", 22);
	}
}

void	play(char *route)
{
	char		*full_route;
	t_map		map;
	t_game		game;

	if (!ber_file(route))
	{
		write(1, "Error: No es un archivo .ber\n", 29);
	}
	else
	{
		full_route = str_join("./maps/", route);
		validate_map(full_route, &game, &map);
	}
}
