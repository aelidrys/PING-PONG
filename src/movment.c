#include "../mini_game.h"

void	mov_paddle(t_game *game)
{
	// mov paddle 1
	if (game->paddle1->m_u == 1 && game->paddle1->y > SIZE*2)
		game->paddle1->y -= game->paddle1->speed;
	if (game->paddle1->m_d == 1 && game->paddle1->y < game->w_size-SIZE*2)
		game->paddle1->y += game->paddle1->speed;
	// mov paddle 2
	if (game->paddle2->m_u == 1 && game->paddle2->y > SIZE*2)
		game->paddle2->y -= game->paddle1->speed;
	if (game->paddle2->m_d == 1 && game->paddle2->y < game->w_size-SIZE*2)
		game->paddle2->y += game->paddle1->speed;
}

void mov_up(t_game *game)
{
	float t_rad;

	t_rad = 3.14 * game->ball->teta / 180;
	if (game->ball->m_u == 0)
		return ;
	if (game->ball->y-SIZE/4 < SIZE){
		game->ball->m_u = 0;
		game->ball->m_d = 1;
		return ;
	}
	game->ball->x += cos(t_rad) * game->ball->speed;
	game->ball->y -= sin(t_rad) * game->ball->speed;

}

void mov_down(t_game *game)
{
	float t_rad;

	t_rad = 3.14 * game->ball->teta / 180;
	if (game->ball->m_d == 0)
		return ;
	if (game->ball->y+SIZE/4 > game->w_size-SIZE){
		game->ball->m_d = 0;
		game->ball->m_u = 1;
		return ;
	}
	game->ball->x -= cos(t_rad) * game->ball->speed;
	game->ball->y += sin(t_rad) * game->ball->speed;
}

void mov_left(t_game *game)
{
	float t_rad;
	t_rad = 3.14 * (game->ball->teta + 90) / 180;
	float x,y;
	x = game->ball->x+cos(t_rad)*game->ball->speed;
	y = game->ball->y+cos(t_rad)*game->ball->speed;
	if (game->ball->m_l == 0)
		return ;
	if (x < SIZE+SIZE/4)
	{
			game->win_2++;
			game->lose_1 = 1;
	}
	if (y > game->paddle2->y-SIZE && y < game->paddle2->y+SIZE){
		if (x < (SIZE*1.75)){
			game->ball->m_r = 1;
			game->ball->m_l = 0;
			if(y < game->paddle2->y-5){
				game->ball->m_d=0;
				game->ball->m_u=1;
			}
			else if(y > game->paddle2->y+5){
				game->ball->m_u=0;
				game->ball->m_d=1;
			}
			else{
				game->ball->m_u=0;
				game->ball->m_d=0;
			}
			return ;
		}
	}
	game->ball->x += cos(t_rad) * game->ball->speed;
	game->ball->y -= sin(t_rad) * game->ball->speed;
}

void mov_rhit(t_game *game)
{
	float t_rad;
	t_rad = 3.14 * (game->ball->teta - 90) / 180;
	float x,y;
	x = game->ball->x+cos(t_rad)*game->ball->speed;
	y = game->ball->y+cos(t_rad)*game->ball->speed;
	if (game->ball->m_r == 0)
		return ;
	if (x > game->w_size-(SIZE)){
			game->win_1++;
			game->lose_2 = 1;
	}
	if (y > game->paddle1->y-SIZE && y < game->paddle1->y+SIZE){
		if (x > game->w_size-(SIZE*1.75)){
			game->ball->m_r = 0;
			game->ball->m_l = 1;
			if(y < game->paddle1->y-5){
				game->ball->m_d=0;
				game->ball->m_u=1;
			}
			else if(y > game->paddle1->y+5){
				game->ball->m_u=0;
				game->ball->m_d=1;
			}
			else{
				game->ball->m_u=0;
				game->ball->m_d=0;
			}
			return ;
		}
	}
	game->ball->x += cos(t_rad) * game->ball->speed;
	game->ball->y -= sin(t_rad) * game->ball->speed;
}
