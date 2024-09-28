#include "../mini_game.h"
int noise(){
    struct timeval t_val;
    gettimeofday(&t_val, NULL);
    time_t time = t_val.tv_sec + (t_val.tv_usec * 1000);
    srand(time);
    int signe = rand()%2;
    if (signe == 0)
        signe = -1;
    int _noise = rand()%50 * signe;
    // printf("signe: %d\n", signe);
    // printf("random: %d\n", _noise);
    return _noise;
}


void boot1(t_game *game)
{
    int ball_y = game->ball->y + noise();
    if (!game->ball->m_r)
        return ;
    if (game->paddle1->y > ball_y && game->paddle1->y > 124)
        game->paddle1->y -= 4;
    if (game->paddle1->y < ball_y && game->paddle1->y < 516)
        game->paddle1->y += 4;
}

void boot2(t_game *game)
{
    int ball_y = game->ball->y + noise();
    if (!game->ball->m_l)
        return ;
    if (game->paddle2->y > ball_y && game->paddle2->y > 124)
        game->paddle2->y -= 4;
    if (game->paddle2->y < ball_y && game->paddle2->y < 516)
        game->paddle2->y += 4;
}