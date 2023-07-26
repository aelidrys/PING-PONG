/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:48:00 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 11:36:53 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mini_game.h"

char	*conv_to_str(int p, int win)
{
	char c = win + 48;
	char *str = malloc(6);
	str[0] = 'P';
	str[1] = '_';
	str[2] = p + 48;
	str[3] = ':';
	str[4] = c;
	str[5] = '\0';
	return (str);
}

void	ft_lose(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 70, 10, 16748815, conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, 500, 10, 16748815, conv_to_str(2,game->win_2));
	mlx_string_put(game->mlx, game->win, 70, 10, 16748815, conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, 500, 10, 16748815, conv_to_str(2,game->win_2));
	if (game->win_1 == 5 || game->win_2 == 5){
		game->lose = 1;
		game->pos = 1;
		if (game->win_2 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->restart1, 0,0);
		if (game->win_1 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->restart2, 0,0);
		if (game->restart){
			game->win_1 = 0;
			game->win_2 = 0;
		}
		else
			return ;
	}
	if (!game->lose_1 && !game->lose_2)
		return ;
	game->lose_1 = 0;
	game->lose_2 = 0;
	game->lose = 0;
	game->restart = 0;
	game->pos = 0;
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
	game->paddle2->y = 240;
}

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(1);
}

void init_var(t_game * game, char *file_name)
{
	game->pos = 0;
	game->restart = 0;
	game->win_1 = 0;
	game->win_2 = 0;
	game->lose = 0;
	game->lose_1 = 0;
	game->lose_2 = 0;
	game->x = 320;
	game->y = 320;
	game->m_r = 0;
	game->m_l = 1;
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
	game->map = spl1(get_next_line(open(file_name, O_RDONLY)), '\n');

}

int main(int ac, char **av)
{
	t_game *game;

	if (!av[1])
		return (0);
	game = malloc(sizeof(t_game));
	game->img = malloc(sizeof(t_imge));
	game->paddle1 = malloc(sizeof(t_paddle));
	game->paddle2 = malloc(sizeof(t_paddle));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 640, "game");
	game->img->ptr = mlx_new_image(game->mlx, 640, 640);
	game->img->addr = mlx_get_data_addr(game->img->ptr, &game->img->bits_per_pixel,
		&game->img->line_length, &game->img->endian);
	game->restart1_1 = mlx_xpm_file_to_image(game->mlx, "img/restart1_1.xpm", &ac, &ac);
	game->restart1_2 = mlx_xpm_file_to_image(game->mlx, "img/restart1_2.xpm", &ac, &ac);
	game->restart2_1 = mlx_xpm_file_to_image(game->mlx, "img/restart2_1.xpm", &ac, &ac);
	game->restart2_2 = mlx_xpm_file_to_image(game->mlx, "img/restart2_2.xpm", &ac, &ac);
	game->restart1 = game->restart1_1;
	game->restart2 = game->restart2_1;
	init_var(game, av[1]);
	randrine(game);
	put_player(game, game->x, game->y, 16711680);
	mlx_hook(game->win, 17, 0, ft_exit, NULL);
	mlx_hook(game->win, 2, 0,presse_key, game);
	mlx_hook(game->win, 3, 0,relesse_key, game);
	mlx_hook(game->win, 6, 0, mouse_event, game);
	mlx_hook(game->win, 4, 0, mouse_presse, game);
	mlx_loop_hook(game->mlx, motion, game);
	mlx_loop(game->mlx);
}