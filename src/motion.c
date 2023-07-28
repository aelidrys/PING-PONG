/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:52:44 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/28 07:41:09 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int motion(t_game *game)
{
	ft_lose(game);
	randrine(game);
	pos(game);
	if (game->pos == 1 || game->lose)
		return (0);
	mov_rhit(game);
	mov_left(game);
	mov_up(game);
	mov_down(game);
	mov_paddle_1(game);
	mov_paddle_2(game);
	return (0);
}

void	pos(t_game *game)
{
	if (!game->pos || !game->start)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->imgs->pos, 0, 0);
}

void	ft_lose(t_game *game)
{
	put_score(game);
	if (game->win_1 == 5 || game->win_2 == 5 || !game->start){
		game->lose = 1;
		if (game->win_2 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->imgs->restart1, 0,0);
		else if (game->win_1 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->imgs->restart2, 0,0);
		else
			mlx_put_image_to_window(game->mlx,game->win,game->imgs->im_start, 0,0);
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
