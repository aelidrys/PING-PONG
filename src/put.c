#include "../mini_game.h"

void	put_square(t_game * game, int old_x, int old_y, int color)
{
	int	x;
	int	y;

	x = old_x;
	while (x < old_x + SIZE)
	{
		y = old_y;
		while (y < old_y + SIZE)
		{
			my_mlx_pixel_put1(game->img, x, y, color);
			y++;
		}
		x++;
	}
}

void	put_ball(t_game *game, float x_p, float y_p, int color)
{
	float	teta = 0;
	float	x,y;
	float	t_rad;
	int		b_ray = game->ball->dimtr/2;
	while (teta < 360)
	{
		x = x_p, y = y_p;
		t_rad = 3.14 * teta / 180;
		while (sqrt(pow(x-x_p,2)+pow(y-y_p,2)) < b_ray){
			my_mlx_pixel_put1(game->img, x, y, color);
			x += cos(teta);
			y -= sin(teta);
		}
		teta += 0.05;
	}
}

void	put_paddle(t_game *game, int s)
{
	t_paddle *p;
	p = game->paddle1;
	if (s == 2)
		p = game->paddle2;
	int x = p->x,y;
	while (x < p->x + SIZE/2)
	{
		y = p->y - SIZE;
		while (y < p->y + SIZE)
			my_mlx_pixel_put1(game->img, x,y++,10377521);
		x++;
	}
}

void	put_score(t_game *game)
{
	mlx_string_put(game->mlx, game->win, SIZE+10, 10, 16748815,
		conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, SIZE*8+10, 10, 16748815,
		conv_to_str(2,game->win_2));
}

void put_background(t_game *game)
{
	int x,y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x]){
			if (game->map[y][x] == '1')
				put_square(game, x * SIZE, y * SIZE, 6565690);
			if (game->map[y][x] == '0')
				put_square(game, x * SIZE, y * SIZE, 0x00FDFD96);
			if (game->map[y][x] == '2')
				put_square(game, x * SIZE, y * SIZE, 6565723);
			if (game->map[y][x] == '3')
				put_square(game, x * SIZE, y * SIZE,  0x01568);
			printf("%d\n",x * SIZE);
			x++;
		}
		y++;
	}
}

