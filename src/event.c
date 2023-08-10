/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:54:18 by aelidrys          #+#    #+#             */
/*   Updated: 2023/08/10 10:29:14 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

int	relesse_key(int key, t_game *game)
{
	if (key == 126 || key == 88)//6
		game->paddle1->m_u = 0;
	if (key == 125 || key == 85)//3
		game->paddle1->m_d = 0;
	if (key == 13)//w
		game->paddle2->m_u = 0;
	if (key == 1)//s
		game->paddle2->m_d = 0;
	return (0);
}

int	presse_key(int key, t_game *game)
{
	if (!game->start)
		return (0);
	if (key == 88 || key == 126)//6
		game->paddle1->m_u = 1;
	if (key == 85 || key == 125)//3
		game->paddle1->m_d = 1;
	if (key == 13)//w
		game->paddle2->m_u = 1;
	if (key == 1)//s
		game->paddle2->m_d = 1;
	if (key == 69 && game->speed < 40)
		game->speed +=  1;
	if (key == 78 && game->speed > 1)
		game->speed -=  1;
	if (key == 53)
		ft_exit();
	return (0);
}

int	mouse_event(int x, int y, t_game *game)
{
	mouse_start(x,y,game);
	mouse_pos(x,y,game);
	mouse_restart(x,y,game);

	return (0);
}

int		mouse_presse(int key, int x, int y, t_game *game)
{
	if (game->start && !game->pos && !game->restart && key == 1
		&& x > 321 && x < 383 && y > 1 && y < 63)
		ft_exit();
	if (game->start && !game->pos && key == 1 && !game->restart
		&& x > 257 && x < 319 && y > 1 && y < 63)
		game->pos = 1;
	if (!game->lose && !game->pos && game->start)
		return (0);
	if (!game->start && key == 1 && x > 80 && x < 600 && y > 394 && y < 560)
		game->start = 1;
	if (game->lose && key == 1 && x > 80 && x < 600 && y > 394 && y < 560){
		game->restart = 1;
		game->lose = 0;
	}
	else if (key == 1 && game->pos && x > 30 && x < 105 && y > 440 && y < 520)
		game->pos = 0;
	else if (key == 1 && game->pos && x > 378 && x < 513 && y > 442 && y < 520)
		ft_exit();
	else if (key == 1 && game->pos && x > 150 && x < 220 && y > 440 && y < 520){
		game->win_1 = 0;
		game->win_2 = 0;
		init_var(game);
	}

	return (0);
}
