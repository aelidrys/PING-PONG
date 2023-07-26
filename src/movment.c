/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:28:59 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/26 14:10:03 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_game.h"

void	mov_paddle_1(t_game *game)
{
	if (game->paddle1->m_u == 1 && game->paddle1->y > 64)
		game->paddle1->y -= 12;
	if (game->paddle1->m_d == 1 && game->paddle1->y < 456)
		game->paddle1->y += 12;
}

void	mov_paddle_2(t_game *game)
{
	if (game->paddle2->m_u == 1 && game->paddle2->y > 64)
		game->paddle2->y -= 12;
	if (game->paddle2->m_d == 1 && game->paddle2->y < 456)
		game->paddle2->y += 12;;
}

void mov_up(t_game *game)
{
	float t_rad;
	float x,y;
	x = game->x+cos(t_rad)*game->speed;
	y = game->y+cos(t_rad)*game->speed;
	t_rad = M_PI * game->teta / 180;

	if (game->m_u == 0)
		return ;
	if (y < 64){
		game->m_u = 0;
		game->m_d = 1;
		return ;
	}
	game->x += cos(t_rad) * game->speed;
	game->y -= sin(t_rad) * game->speed;

}

void mov_down(t_game *game)
{
	float t_rad;
	t_rad = M_PI * game->teta / 180;
	float x,y;
	x = game->x+cos(t_rad)*game->speed;
	y = game->y+cos(t_rad)*game->speed;
	if (game->m_d == 0)
		return ;
	if (y > 576){
		game->m_d = 0;
		game->m_u = 1;
		return ;
	}
	game->x -= cos(t_rad) * game->speed;
	game->y += sin(t_rad) * game->speed;
}

void mov_left(t_game *game)
{
	float t_rad;
	t_rad = M_PI * (game->teta + 90) / 180;
	float x,y;
	x = game->x+cos(t_rad)*game->speed;
	y = game->y+cos(t_rad)*game->speed;
	if (game->m_l == 0)
		return ;
	if (x < 80)
	{
			game->win_2++;
			game->lose_1 = 1;
		// if (!game->lose_1){
		// 	printf("%d\n", game->win_2);
		// }
	}
	// else
	// 	game->lose_1 = 0;
	if (y > game->paddle2->y && y < game->paddle2->y+120){
		if (x < 112){
			game->m_r = 1;
			game->m_l = 0;
			if(y < game->paddle2->y+60){
				game->m_d=0;
				game->m_u=1;
			}
			else if(y != game->paddle2->y+60){
				game->m_u=0;
				game->m_d=1;
			}
			return ;
		}
	}
	game->x += cos(t_rad) * game->speed;
	game->y -= sin(t_rad) * game->speed;
}

void mov_rhit(t_game *game)
{
	float t_rad;
	t_rad = M_PI * (game->teta - 90) / 180;
	float x,y;
	x = game->x+cos(t_rad)*game->speed;
	y = game->y+cos(t_rad)*game->speed;
	if (game->m_r == 0)
		return ;
	if (x > 560){
			game->win_1++;
			game->lose_2 = 1;
		// if (!game->lose_2){
		// 	printf("%d\n", game->win_1);
		// }
	}
	// else
	// 	game->lose_2 = 0;
	if (y > game->paddle1->y && y < game->paddle1->y+120){
		if (x > 528){
			game->m_r = 0;
			game->m_l = 1;
			if(y < game->paddle1->y+60){
				game->m_d=0;
				game->m_u=1;
			}
			else if(y != game->paddle1->y+60){
				game->m_u=0;
				game->m_d=1;
			}
			return ;
		}
	}
	game->x += cos(t_rad) * game->speed;
	game->y -= sin(t_rad) * game->speed;
}
