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

	if (game->pos && x > 65 && x < 151 && y > 503 && y < 587)
		game->imgs->pos = game->imgs->pos_1;
	else if (game->pos && x > 209 && x < 293 && y > 503 && y < 587)
		game->imgs->pos = game->imgs->pos_2;
	else if (game->pos && x > 349 && x < 433 && y > 503 && y < 587)
		game->imgs->pos = game->imgs->pos_3;
	else if (game->pos && x > 500 && x < 574 && y > 503 && y < 587)
		game->imgs->pos = game->imgs->pos_4;
	else if (game->pos)
		game->imgs->pos = game->imgs->pos_0;
}

void	mouse_start(int x, int y, t_game *game)
{
	if (!game->start && x > 89 && x < 549 && y > 372 && y < 478){
		game->imgs->home = game->imgs->play_n;
	}
	else if (!game->start)
		game->imgs->home = game->imgs->home1;
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
