/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:26 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 19:51:55 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	can_move(t_game game, int c)
{
	int	x;
	int	y;
	int	b;

	b = 1;
	x = game.player.px;
	y = game.player.py;
	if (c == 119)
		y--;
	else if (c == 115)
		y++;
	else if (c == 97)
		x--;
	else if (c == 100)
		x++;
	if ((game.map.alloc[y][x] == 'E'
		&& game.map.n_collectibles == game.player.collectibles_taken))
		close_game(&game);
	else if (game.map.alloc[y][x] == '1')
		b = 0;
	return (b);
}

void	update_position(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = game->player.px;
	py = game->player.py;
	if (game->map.alloc[y][x] == 'C')
		game->player.collectibles_taken++;
	game->player.px = x;
	game->player.py = y;
	game->map.alloc[y][x] = 'P';
	if (px == game->map.px_exit && py == game->map.py_exit)
		game->map.alloc[py][px] = 'E';
	else
		game->map.alloc[py][px] = '0';
}

void	move(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->player.px;
	y = game->player.py;
	if (can_move(*game, keycode))
	{
		if (keycode == 119)
			y--;
		else if (keycode == 115)
			y++;
		else if (keycode == 97)
			x--;
		else if (keycode == 100)
			x++;
		update_position(game, x, y);
		print_map(*game);
	}
}
