/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarpio- <rcarpio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:10:59 by rcarpio-          #+#    #+#             */
/*   Updated: 2025/03/03 18:08:17 by rcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/Xlib.h>
# include "./aux/aux.h"
# include "./process_map/process_map.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "gnl/get_next_line.h"

typedef struct s_player
{
	int	py;
	int	px;
	int	moves;
	int	collectibles_taken;
}	t_player;

typedef struct s_map
{
	int			n_collectibles;
	int			size_x;
	int			size_y;
	int			px_exit;
	int			py_exit;
	t_player	player;
	char		**alloc;
}	t_map;

typedef struct s_game
{
	void		*window;
	void		*mlx;
	void		*wall;
	void		*floor;
	void		*exit;
	void		*collectible;
	void		*character;
	t_player	player;
	t_map		map;
	int			pixels;
}	t_game;

#endif
