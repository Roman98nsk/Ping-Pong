#include <stdio.h>
#include "../include/Pong_functions.h"

void CleanerScreen() {
    printf("\033[2J");
}

int main() {
    int n = 0;

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

    while(1) {
        printf("Do you want continue game? Input \033[4m'1' to continue\033[0m or \033[4m'0' to quit\033[0m: ");
        scanf("%d", &n);
        if (n == 1) {
            game(ball_x, ball_y, HEIGHT, WIDTH, vector_x, vector_y, left_rocket, right_rocket, score_right_player, score_left_player);
        } else {
            return 0;
        }
    }
return 0;
}
