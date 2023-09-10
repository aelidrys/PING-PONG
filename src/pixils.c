#include "../mini_game.h"

void	my_mlx_pixel_put1(t_imge *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= SIZE*10 || y < 0 || y >= SIZE*10)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int		get_pixel(t_game *game, int x, int y)
// {
// 	char	*dst;
// 	if (x < 0 || x >= 640 || y < 0 || y >= 640)
// 		return ;
// 	dst = game->img->addr + (y * game->img->line_length + x * (game->img->bits_per_pixel / 8));
// 	return (*(unsigned int*)dst);
// }
