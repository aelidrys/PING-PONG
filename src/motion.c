/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:52:44 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 20:58:44 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int motion(t_game *game)
{
	ft_lose(game);
	randrine(game);
	if (game->pos == 1)
		return (0);
	mov_rhit(game);
	mov_left(game);
	mov_up(game);
	mov_down(game);
	mov_paddle_1(game);
	mov_paddle_2(game);
	return (0);
}

void	ft_lose(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 70, 10, 16748815, conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, 500, 10, 16748815, conv_to_str(2,game->win_2));
	mlx_string_put(game->mlx, game->win, 70, 10, 16748815, conv_to_str(1,game->win_1));
	mlx_string_put(game->mlx, game->win, 500, 10, 16748815, conv_to_str(2,game->win_2));
	if (game->win_1 == 5 || game->win_2 == 5 || !game->start){
		game->lose = 1;
		game->pos = 1;
		if (game->win_2 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->restart1, 0,0);
		if (game->win_1 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->restart2, 0,0);
		else
			mlx_put_image_to_window(game->mlx,game->win,game->im_start, 0,0);
		if (game->restart){
			game->win_1 = 0;
			game->win_2 = 0;
		}
		else
			return ;
	}
	if (!game->lose_1 && !game->lose_2)
		return ;
	init_var(game);
}
