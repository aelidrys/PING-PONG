#include "../mini_game.h"

void	my_mlx_pixel_put1(t_imge *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= SIZE*10 || y < 0 || y >= SIZE*10)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

