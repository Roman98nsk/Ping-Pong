#include <stdio.h>
#include "Pong_functions.h"
      
int score(int score_left_player, int score_right_player) {
    if (score_left_player != 1 || score_right_player != 1) {
        printf("\t\t%d : %d", score_left_player, score_right_player);
        printf("\n    \"Left_player\" : \"Right_player\"\n");
    }

    if (score_left_player == 1) {
        printf("\n\033[1;32mCONGRATULATION!!! LEFT PLAYER IS WON. SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
        return 1;
    } else if (score_right_player == 1) {
        printf("\n\033[1;32mCONGRATULATION!!! RIGHT PLAYER IS WON. SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
        return 1;
    }
return 0;
}

int game(int ball_x, int ball_y, int HEIGHT, int WIDTH, int vector_x, int vector_y, int left_rocket, int right_rocket,
                                                                            int score_right_player, int score_left_player) {

    while (score_left_player != 1 || score_right_player != 1) {
        draw(left_rocket, right_rocket, ball_x, ball_y, HEIGHT, WIDTH);

        if (score(score_left_player, score_right_player) == 1) {
            return 0;
        } else {
            char temp = getchar();
            if (temp == 'q') {
                printf("%s\n", "\033[3;31mGAME OVER!\033[0m");
                return 0;
            } else {
                switch (temp) {
                case 'a':
                    (left_rocket != 1) ? (left_rocket -= 1) : left_rocket;
                    break;
                case 'z':
                    left_rocket != HEIGHT - 4 ? left_rocket += 1 : left_rocket;
                    break;
                case 'k':
                    (right_rocket != 1) ? (right_rocket -= 1) : right_rocket;
                    break;
                case 'm':
                    right_rocket != HEIGHT - 4 ? right_rocket += 1 : right_rocket;
                    break;
                }

                if (ball_y == 1 || ball_y == HEIGHT - 2) {
                    vector_y = -(vector_y);
                }
                if (ball_x == 3 && (ball_y == left_rocket - 1 || ball_y == left_rocket || ball_y == left_rocket + 1)) {
                    vector_x = -(vector_x);
                } else if (ball_x == 1 && (ball_y != left_rocket - 1 || ball_y != left_rocket || ball_y != left_rocket + 1)) {
                    score_right_player++;
                }
                if (ball_x == WIDTH - 3 && (ball_y == right_rocket - 1 || ball_y == right_rocket || ball_y == right_rocket + 1)) {
                    vector_x = -(vector_x);
                } else if (ball_x == 38 && (ball_y != right_rocket - 1 || ball_y != right_rocket || ball_y != right_rocket + 1)) {
                    score_left_player++;
                }

                ball_y += vector_y;
                ball_x += vector_x;
            }
        }
    }
return 0;
}

void draw(int left_rocket, int right_rocket, int ball_x, int ball_y, int HEIGHT, int WIDTH) {
    CleanerScreen();

    printf("\033[34m ---------------------\n"
         "|         Menu        |\n"
         "|                     |\n"
         "|  q - Quit           |\n"
         "|                     |\n"
         "|  a - Up for left    |\n"
         "|  z - Down for left  |\n"
         "|                     |\n"  
         "|  k - Up for right   |\n"
         "|  m - Down for right |\n"
         " ---------------------\033[0m");
    printf("\n\n");

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH - 1) || (y == HEIGHT - 1 && x != 0 && x != WIDTH - 1)) {
                printf("-");
            }
            else if (((x == 0 && y != 0 && y != HEIGHT - 1) || (x == WIDTH - 1 && y != 0 && y != HEIGHT - 1))) {
                printf("|");
            }
            else if (x == 1 && (y == left_rocket || y == left_rocket + 1 || y == left_rocket + 2)) {
                printf("X");
            }
            else if (x == WIDTH - 2 && (y == right_rocket || y == right_rocket + 1 || y == right_rocket + 2)) {
                printf("X");
            }
            else if (x == ball_x && y != 0 && y == ball_y) {
                printf("o");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
