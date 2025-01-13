#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "so_long.h"

int	close_window(w_data *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

int	handler_key(int key, w_data *data)
{
	if (key == 65307)
		close_window(data);
	return (0);
}

int	main(void)
{
	void	*mlx;
	w_data	window;

	mlx = mlx_init();

	window.mlx = mlx;
	window.win = mlx_new_window(window.mlx, 800, 800, "test");

	mlx_hook(window.win, 2, 1L << 0, handler_key, &window);
	mlx_loop(window.mlx);

	return (0);
}