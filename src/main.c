# include "../mini_game.h"

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

int	ft_exit(void)
{
	write(1,"YOU ARE EXIT FROM CUB\n",22);
	exit(1);
}

int main(int ac, char **av)
{
	t_game *game;

	if (!av[1]){
		printf("no map\n");
		return (0);
	}
	game = malloc(sizeof(t_game));
	game->img = malloc(sizeof(t_imge));
	game->ball = malloc(sizeof(t_ball));
	game->imgs = malloc(sizeof(t_imgs));
	game->paddle1 = malloc(sizeof(t_paddle));
	game->paddle2 = malloc(sizeof(t_paddle));
	init_var(game);
	init_img_win(game, av[1]);
	game->start = 0;
	randrine(game);
	put_ball(game, game->ball->x, game->ball->y, 16711680);

	// MAC
	// mlx_hook(game->win, 17, 0, ft_exit, NULL);
	// mlx_hook(game->win, 2, 0,presse_key_m, game);
	// mlx_hook(game->win, 3, 0,relesse_key_m, game);
	// mlx_hook(game->win, 6, 0, mouse_event, game);
	// mlx_hook(game->win, 4, 0, mouse_presse, game);

	// Ubonto
	mlx_hook(game->win, 17, (1L<<0), ft_exit, NULL);
	mlx_hook(game->win, 2, (1L<<0),presse_key, game);
	mlx_hook(game->win, 3, (1L<<1),relesse_key, game);
	mlx_hook(game->win, 6, (1L<<6), mouse_event, game);
	mlx_hook(game->win, 4, (1L<<2), mouse_presse, game);
	mlx_loop_hook(game->mlx, motion, game);
	
	mlx_loop(game->mlx);
}