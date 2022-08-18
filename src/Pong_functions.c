#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "../include/Pong_functions.h"

void draw_menu() {
    CleanerScreen();
    printf("\033[34m ---------------------\n"
         "|         Menu        |\n"
         "|                     |\n"
         "|  q - Quit/Restart   |\n"
         "|                     |\n"
         "|  a - Up for left    |\n"
         "|  z - Down for left  |\n"
         "|                     |\n"  
         "|  k - Up for right   |\n"
         "|  m - Down for right |\n"
         " ---------------------\033[0m");
    printf("\n\n");
}

int mt_getscreensize(int *rows, int *cols) {
    struct winsize ws;
    ioctl(1, TIOCGWINSZ, &ws);
    *rows = ws.ws_row - 5;
    *cols = ws.ws_col;
return 0;
}

void draw_area(int left_rocket, int right_rocket, int ball_x, int ball_y, int HEIGHT, int WIDTH) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if ((y == 0 && x != 0 && x != WIDTH - 1) || (y == HEIGHT - 1 && x != 0 && x != WIDTH - 1)) {
                printf("-");
            } else if (((x == 0 && y != 0 && y != HEIGHT - 1) || (x == WIDTH - 1 && y != 0 && y != HEIGHT - 1))) {
                printf("|");
            } else if (x == 1 && (y == left_rocket || y == left_rocket + 1 || y == left_rocket + 2)) {
                printf("X");
            } else if (x == WIDTH - 2 && (y == right_rocket || y == right_rocket + 1 || y == right_rocket + 2)) {
                printf("X");
            } else if (x == ball_x && y != 0 && y == ball_y) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int score(int score_left_player, int score_right_player) {
    int part = 1, score_difference = 0, score_part_left_player = 0, score_part_right_player = 0;
    
    score_difference = abs(score_left_player - score_right_player);

    if (score_left_player != 2 || score_right_player != 2) {
        printf("\t\tGame %d"
        "\n\t\t\033[1:32m%d : %d\033[0m"
        "\n    \"Left_player\" : \"Right_player\"\n"
        "\t%d \t\t    %d\n", part, score_left_player, score_right_player, score_part_left_player, score_part_right_player);
    }

    if ((score_left_player == 2 || score_left_player > 2) && score_difference >= 2) {
        printf("\n\033[1;32mLEFT PLAYER WON GAME!\nGAME SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
        part++;
        score_part_left_player++;
    } else if ((score_right_player == 2 || score_right_player > 2) && score_difference >= 2) {
        printf("\n\033[1;32mRIGHT PLAYER WON GAME!\nGAME SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
        part++;
        score_part_right_player++;
    }

    if (part > 2) {
        printf("\033[1;32mTOTAL SCORE: %d : %d\033[0m\n", score_part_left_player, score_part_right_player);
        if (score_part_left_player > score_part_right_player) {
            printf("\n\033[1;32mCONGRATULATION!!! LEFT PLAYER CHAMPION!\033[0m\n\n");
        } else {
            printf("\n\033[1;32mCONGRATULATION!!! RIGHT PLAYER CHAMPION!\033[0m\n\n");
        }
        return 0;
    }
return 0;
}

int game(int ball_x, int ball_y, int HEIGHT, int WIDTH, int vector_x, int vector_y, int left_rocket, int right_rocket,
                                                                        int score_right_player, int score_left_player) {
    do {
        draw_menu();
        draw_area(left_rocket, right_rocket, ball_x, ball_y, HEIGHT, WIDTH);
        score(score_left_player, score_right_player);
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
        } else if (ball_x == WIDTH - 2 && (ball_y != right_rocket - 1 || ball_y != right_rocket || ball_y != right_rocket + 1)) {
            score_left_player++;
        }
        ball_y += vector_y;
        ball_x += vector_x;
    } while (score_left_player != 2 || score_right_player != 2);
return 0;
}
