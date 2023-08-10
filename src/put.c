/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:56:56 by aelidrys          #+#    #+#             */
/*   Updated: 2023/08/10 10:37:12 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

void	put_square(t_game * game, int old_x, int old_y, int color)
{
	int	x;
	int	y;

	x = old_x;
	while (x < old_x + 64)
	{
		y = old_y;
		while (y < old_y + 64)
		{
			my_mlx_pixel_put1(game->img, x, y, color);
			y++;
		}
		x++;
	}
}

void	put_ball(t_game *game, float x_p, float y_p, int color)
{
	float teta = 0;
	float x,y;
	float t_rad;
	while (teta < 360)
	{
		x = x_p, y = y_p;
		t_rad = M_PI * teta / 180;
		while (sqrt(pow(x-x_p,2)+pow(y-y_p,2)) < 16){
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
	while (x < p->x + 32)
	{
		y = p->y;
		while (y < p->y + 120)
			my_mlx_pixel_put1(game->img, x,y++,10377521);
		x++;
	}
}

void	put_score(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 70, 10, 16748815,
		conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, 518, 10, 16748815,
		conv_to_str(2,game->win_2));
}

void randrine(t_game *game)
{
	if (game->lose)
		return ;
	put_score(game);
	int x,y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x]){
			if (game->map[y][x] == '1')
				put_square(game, x * 64, y * 64, 6565690);
			if (game->map[y][x] == '0')
				put_square(game, x * 64, y * 64, 0x00FDFD96);
			if (game->map[y][x] == '2')
				put_square(game, x * 64, y * 64, 6565723);
			if (game->map[y][x] == '3')
				put_square(game, x * 64, y * 64, 0x00FF000080);
			x++;
		}
		y++;
	}
	put_ball(game, game->x, game->y, 6565723);
	put_paddle(game,1);
	put_paddle(game,2);
	mlx_put_image_to_window(game->mlx, game->win, game->img->ptr, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs->pos_g, 256, 0);
}
