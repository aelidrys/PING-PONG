/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:54:18 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/28 19:44:34 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int	relesse_key(int key, t_game *game)
{
	if (key == 88)//6
		game->paddle1->m_u = 0;
	if (key == 85)//3
		game->paddle1->m_d = 0;
	if (key == 13)//w
		game->paddle2->m_u = 0;
	if (key == 1)//s
		game->paddle2->m_d = 0;
	if (key == 126)
		game->m_u = 0;
	if (key == 125)
		game->m_d = 0;
	if (key == 124)
		game->m_r = 0;
	if (key == 123)
		game->m_l = 0;
	return (0);
}

int	presse_key(int key, t_game *game)
{
	if (key == 35 && game->pos == 0)
		game->pos = 1;
	else if (key == 35 && game->pos == 1)
		game->pos = 0;
	// if (key == 49)
	// 	game->lose = 0;
	if (key == 88)//6
		game->paddle1->m_u = 1;
	if (key == 85)//3
		game->paddle1->m_d = 1;
	if (key == 13)//w
		game->paddle2->m_u = 1;
	if (key == 1)//s
		game->paddle2->m_d = 1;
	if (key == 69 && game->speed < 40)
		game->speed +=  1;
	if (key == 78 && game->speed > 1)
		game->speed -=  1;
	if (key == 126)
		game->m_u = 1;
	if (key == 125)
		game->m_d = 1;
	if (key == 124)
		game->m_r = 1;
	if (key == 123)
		game->m_l = 1;
	if (key == 53)
		ft_exit();
	return (0);
}

int	mouse_event(int x, int y, t_game *game)
{
	if (game->lose && x > 80 && x < 600 && y > 394 && y < 560){
		game->imgs->im_start = game->imgs->im_start2;
		game->imgs->restart1 = game->imgs->restart1_2;
		game->imgs->restart2 = game->imgs->restart2_2;
	}
	else if (game->lose) {
		game->imgs->im_start = game->imgs->im_start1;
		game->imgs->restart1 = game->imgs->restart1_1;
		game->imgs->restart2 = game->imgs->restart2_1;
	}
	if (game->pos && x > 30 && x < 105 && y > 440 && y < 520)
		game->imgs->pos = game->imgs->pos_1;
	else if (game->pos && x > 150 && x < 220 && y > 440 && y < 520)
		game->imgs->pos = game->imgs->pos_2;
	else if (game->pos && x > 269 && x < 338 && y > 440 && y < 520)
		game->imgs->pos = game->imgs->pos_3;
	else if (game->pos && x > 378 && x < 513 && y > 442 && y < 520)
		game->imgs->pos = game->imgs->pos_4;
	else if (game->pos)
		game->imgs->pos = game->imgs->pos_0;
	return (0);
}

int		mouse_presse(int key, int x, int y, t_game *game)
{
	if (!game->lose && !game->pos)
		return (0);
	if (game->lose && key == 1 && x > 80 && x < 600 && y > 394 && y < 560){

		game->start = 1;
		game->restart = 1;
		game->lose = 0;
	}
	else if (game->pos && x > 30 && x < 105 && y > 440 && y < 520)
		game->pos = 0;
	else if (game->pos && x > 378 && x < 513 && y > 442 && y < 520)
		ft_exit();
	else if (game->pos && x > 150 && x < 220 && y > 440 && y < 520){
		game->win_1 = 0;
		game->win_2 = 0;
		init_var(game);
	}

	return (0);
}
