#include <stdio.h>
#include "Pong_functions.h"

void CleanerScreen() {
    printf("\033[2J");
}

int main() {
    int HEIGHT = 12;
    int WIDTH = 40;

    int score_left_player = 0;
    int score_right_player = 0;

    int left_rocket = 5;   //верхняя координата ракетки
    int right_rocket = 5;

    int ball_x = 2;
    int ball_y = 6;
    int vector_x = 1;
    int vector_y = 1;

    game(ball_x, ball_y, HEIGHT, WIDTH, vector_x, vector_y, left_rocket, right_rocket, score_right_player, score_left_player);
return 0;
}
