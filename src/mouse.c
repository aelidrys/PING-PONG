/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:45:52 by aelidrys          #+#    #+#             */
/*   Updated: 2023/08/01 15:56:24 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"


void	mouse_pos(int x, int y, t_game *game)
{
	if (game->start && !game->pos && !game->restart
		&& x > 321 && x < 383 && y > 1 && y < 63)
		game->imgs->pos_g = game->imgs->pos_g2;
	else if (game->start && !game->pos && !game->restart
		&& x > 257 && x < 319 && y > 1 && y < 63)
		game->imgs->pos_g = game->imgs->pos_g1;
	else
		game->imgs->pos_g = game->imgs->pos_g0;

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
}

void	mouse_start(int x, int y, t_game *game)
{
	if (!game->start && x > 80 && x < 600 && y > 394 && y < 560)
		game->imgs->im_start = game->imgs->im_start2;
	else if (!game->start)
		game->imgs->im_start = game->imgs->im_start1;
}

void	mouse_restart(int x, int y, t_game *game)
{
	if (game->lose && x > 80 && x < 600 && y > 394 && y < 560){
		game->imgs->restart1 = game->imgs->restart1_2;
		game->imgs->restart2 = game->imgs->restart2_2;
	}
	else if (game->lose) {
		game->imgs->restart1 = game->imgs->restart1_1;
		game->imgs->restart2 = game->imgs->restart2_1;
	}
}
