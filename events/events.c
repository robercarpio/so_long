/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:20 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 20:35:44 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		game->player.moves++;
		put_int(game->player.moves);
		write(1, "\n", 1);
		move(game, keycode);
	}
	else if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->window);
		close_game(game);
		free(game);
	}
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->character);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->collectible);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->wall);
	free(game->mlx);
	free_map(game->map.alloc);
	exit(-1);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
