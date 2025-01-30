#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/Xlib.h>
#include "./aux/aux.h"
#include "./process_map/process_map.h"
#include "./print_map/print_map.h"
#include "./minilibx-linux/mlx.h"
#include "./minilibx-linux/mlx_int.h"
#include "gnl/get_next_line.h"

typedef struct w_data {
	void	*mlx;
	void	*win;
} w_data;

#endif
