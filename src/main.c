/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:48:00 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 20:55:04 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (!av[1])
		return (0);
	game = malloc(sizeof(t_game));
	game->img = malloc(sizeof(t_imge));
	game->paddle1 = malloc(sizeof(t_paddle));
	game->paddle2 = malloc(sizeof(t_paddle));
	init_img_win(game, av[1]);
	game->start = 0;
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