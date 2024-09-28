#include "../mini_game.h"
int noise(){
    struct timeval t_val;
    gettimeofday(&t_val, NULL);
    time_t time = t_val.tv_sec + (t_val.tv_usec * 1000);
    srand(time);
    printf("random: %zu\n", time);
    printf("random: %d\n", rand()%50);
    return rand()%50;
}

int main(){
    noise();
}