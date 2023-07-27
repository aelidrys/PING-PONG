/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:42:31 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 21:00:08 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

void	init_var(t_game * game)
{
	game->pos = 0;
	game->restart = 0;
	game->lose = 0;
	game->lose_1 = 0;
	game->lose_2 = 0;
	game->x = 320;
	game->y = 320;
	game->m_r = 1;
	game->m_l = 0;
	game->m_u = 0;
	game->m_d = 0;
	game->rot_rhit = 0;
	game->rot_left = 0;
	game->teta = 90;
	game->speed = 6;
	game->paddle1->m_u = 0;
	game->paddle1->m_d = 0;
	game->paddle1->m_u = 0;
	game->paddle1->m_d = 0;
	game->paddle1->x = 544;
	game->paddle1->y = 240;
	game->paddle2->x = 64;
	game->paddle2->y = 250;

}

void	init_img_win(t_game *game, char *file_name)
{
	int	ac;
	game->map = spl1(get_next_line(open(file_name, O_RDONLY)), '\n');
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 640, "game");
	game->img->ptr = mlx_new_image(game->mlx, 640, 640);
	game->img->addr = mlx_get_data_addr(game->img->ptr, &game->img->bits_per_pixel,
		&game->img->line_length, &game->img->endian);
	game->im_start1 = mlx_xpm_file_to_image(game->mlx, "img/start1.xpm", &ac, &ac);
	game->im_start2 = mlx_xpm_file_to_image(game->mlx, "img/start2.xpm", &ac, &ac);
	game->im_start = game->im_start1;

	game->restart1_1 = mlx_xpm_file_to_image(game->mlx, "img/restart1_1.xpm", &ac, &ac);
	game->restart1_2 = mlx_xpm_file_to_image(game->mlx, "img/restart1_2.xpm", &ac, &ac);
	game->restart2_1 = mlx_xpm_file_to_image(game->mlx, "img/restart2_1.xpm", &ac, &ac);
	game->restart2_2 = mlx_xpm_file_to_image(game->mlx, "img/restart2_2.xpm", &ac, &ac);
	game->restart1 = game->restart1_1;
	game->restart2 = game->restart2_1;
	game->win_1 = 0;
	game->win_2 = 0;
}
