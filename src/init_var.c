#include "../mini_game.h"

void	init_var(t_game * game)
{
	game->pos = 0;
	game->restart = 0;
	game->lose = 0;
	game->lose_1 = 0;
	game->lose_2 = 0;
	game->w_size =640;
	game->ball->x = 320;
	game->ball->y = 320;
	game->ball->m_r = 1;
	game->ball->m_l = 0;
	game->ball->m_u = 0;
	game->ball->m_d = 0;
	game->ball->rot_rhit = 0;
	game->ball->rot_left = 0;
	game->ball->teta = 90;
	game->ball->speed = 6;
	game->ball->dimtr = SIZE/2;
	game->paddle1->m_u = 0;
	game->paddle1->m_d = 0;
	game->paddle1->m_u = 0;
	game->paddle1->m_d = 0;
	game->paddle1->x = game->w_size-(SIZE*1.5);
	game->paddle1->y = game->w_size/2;
	game->paddle2->x = SIZE;
	game->paddle2->y =	game->w_size/2;
	game->paddle1->speed = 8;

}

void	init_img_win(t_game *game, char *file_name)
{
	int	ac;
	game->map = spl1(get_next_line(open(file_name, O_RDONLY)), '\n');
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,game->w_size,game->w_size,"game");
	game->img->ptr = mlx_new_image(game->mlx, game->w_size, game->w_size);
	game->img->addr = mlx_get_data_addr(game->img->ptr, &game->img->bits_per_pixel,
		&game->img->line_length, &game->img->endian);
	game->imgs->home1 = mlx_xpm_file_to_image(game->mlx, "img/home.xpm", &ac, &ac);
	game->imgs->play_n = mlx_xpm_file_to_image(game->mlx, "img/play_n.xpm", &ac, &ac);
	game->imgs->play_ai = mlx_xpm_file_to_image(game->mlx, "img/play_ai.xpm", &ac, &ac);
	game->imgs->home = game->imgs->home1;

	game->imgs->restart1_1 = mlx_xpm_file_to_image(game->mlx, "img/restart1_1.xpm", &ac, &ac);
	game->imgs->restart1_2 = mlx_xpm_file_to_image(game->mlx, "img/restart1_2.xpm", &ac, &ac);
	game->imgs->restart2_1 = mlx_xpm_file_to_image(game->mlx, "img/restart2_1.xpm", &ac, &ac);
	game->imgs->restart2_2 = mlx_xpm_file_to_image(game->mlx, "img/restart2_2.xpm", &ac, &ac);
	game->imgs->restart1 = game->imgs->restart1_1;
	game->imgs->restart2 = game->imgs->restart2_1;
	game->win_1 = 0;
	game->win_2 = 0;

	game->imgs->pos_g0 = mlx_xpm_file_to_image(game->mlx, "img/pos_g0.xpm", &ac, &ac);
	game->imgs->pos_g1 = mlx_xpm_file_to_image(game->mlx, "img/pos_g1.xpm", &ac, &ac);
	game->imgs->pos_g2 = mlx_xpm_file_to_image(game->mlx, "img/pos_g2.xpm", &ac, &ac);
	game->imgs->pos_g = game->imgs->pos_g0;

	game->imgs->pos_0 = mlx_xpm_file_to_image(game->mlx, "img/norml_pos.xpm", &ac, &ac);
	game->imgs->pos_1 = mlx_xpm_file_to_image(game->mlx, "img/play.xpm", &ac, &ac);
	game->imgs->pos_2 = mlx_xpm_file_to_image(game->mlx, "img/replay.xpm", &ac, &ac);
	game->imgs->pos_3 = mlx_xpm_file_to_image(game->mlx, "img/grid.xpm", &ac, &ac);
	game->imgs->pos_4 = mlx_xpm_file_to_image(game->mlx, "img/quit.xpm", &ac, &ac);
	game->imgs->pos = game->imgs->pos_0;
}
