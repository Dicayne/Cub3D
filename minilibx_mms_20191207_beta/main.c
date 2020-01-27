#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "mlx.h"
#include "../Libft/header/libft.h"
#define screenwidth 1920
#define screenheight 1080
typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}				data_t;

int main(void)
{
	data_t	data;
	int x;
	int y;
	int fond;
	int w;
	int z;
	double ang;

	x = 0;
	ang = 15.5;
	w = screenheight / 6;
	z = screenheight - w;
	fond = screenwidth / 3;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, screenwidth, screenheight, "Cub3D")) == NULL)
		return (EXIT_FAILURE);
	while (x < screenwidth)
	{
		y = 0;
		while (y < screenheight / 2)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0x1e90ff);
			y++;
		}
		while (y < screenheight)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0x6b8e23);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < screenwidth)
	{
		if (x < fond)
		{
			if (w < screenheight / 3)
				w = ((fond - x) * tan(ang)) + (screenheight / 3);
			y = w;
			while (y < z)
			{
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xff4500);
				y++;
			}
			if (z > (screenheight / 3) * 2)
				z = ((screenheight / 3) * 2) - ((fond - x) * tan(ang));
		}
		else if (x > fond * 2)
		{
			if (w >= screenheight / 6)
				w = ((screenheight / 6) * 2) + ((x - fond * 2) * tan(ang));
			y = w;
			while (y < z)
			{
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xff4500);
				y++;
			}
			if (z <= screenheight - (screenheight / 6))
				z = ((screenheight / 3) * 2) - ((x - fond * 2) * tan(ang));
		}
		else
		{
			y = screenheight / 3;
			while (y < screenheight / 3 * 2)
			{
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xff0000);
				y++;
			}
		}
		x++;
	}
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
