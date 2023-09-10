#include "../mini_game.h"

void boot(t_game *game)
{
    if (!game->ball->m_l)
        return ;
    if (game->paddle2->y > game->ball->y && game->paddle2->y > 124)
        game->paddle2->y -= 1;
    if (game->paddle2->y < game->ball->y && game->paddle2->y < 516)
        game->paddle2->y += 1;
}