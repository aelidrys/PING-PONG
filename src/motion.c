/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:52:44 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/29 08:31:18 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int motion(t_game *game)
{
	ft_start(game);
	ft_pos(game);
	ft_lose(game);
	if (game->pos || game->lose || !game->start)
		return (0);
	randrine(game);
	mov_rhit(game);
	mov_left(game);
	mov_up(game);
	mov_down(game);
	mov_paddle_1(game);
	mov_paddle_2(game);
	return (0);
}

void	ft_pos(t_game *game)
{
	if (!game->pos || !game->start || game->restart)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->imgs->pos, 0, 0);
}

void	ft_start(t_game *game)
{
	if (!game->start)
		mlx_put_image_to_window(game->mlx,game->win,game->imgs->im_start, 0,0);
}

void	ft_lose(t_game *game)
{
	if (!game->start)
		return ;
	if (game->win_1 == 5 || game->win_2 == 5){
		game->lose = 1;
		if (game->win_2 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->imgs->restart1, 0,0);
		else if (game->win_1 == 5)
			mlx_put_image_to_window(game->mlx,game->win,game->imgs->restart2, 0,0);
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
