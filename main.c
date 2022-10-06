#include <mlx.h>
#include <stdio.h>
#include <string.h>

int	working(void *param)
{
	long int	key;

	key = (long int) param;
	if (key == 0xff52)
		printf("cima\n");
	else if (key == 0xff54)
		printf("baixo\n");
	else if (key == 0xff51)
		printf("esquerda\n");
	else if (key == 0xff53)
		printf("direita\n");
	else
		printf("errou\n");
	return (0);
}

int	mouse(void *param)
{
	long int	click;

	click = (long int) param;
	printf("Click: %li\n", click);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1024, 668, "Not my first window anymore!");
	mlx_key_hook(window, working, NULL);
	mlx_mouse_hook(window, mouse, NULL);
	mlx_loop(mlx);
	return (0);
}