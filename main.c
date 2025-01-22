#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "so_long.h"

void	ft_putnbr(int n)
{
	char	c;

	c = 0;
	if(n >= 10)
		ft_putnbr(n/10);
	c = n % 10 + '0';
	write(1,&c,1);
}

int	close_window(w_data *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

int	handler_key(int key, w_data *data)
{
	static int	moves = 0;
	if (key == 65307)
		close_window(data);
	else if ((key >= 65361 && key <= 65364) || key == 119 || key == 97 || key == 115 || key == 100)

	{
		ft_putnbr(moves);
		write(1,"\n",1);
		moves++;
	}
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