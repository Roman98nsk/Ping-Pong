#include <stdio.h>

int HEIGHT = 12;
int WIDTH = 40;
int left_rocket = 5;   //верхняя координата ракетки
int right_rocket = 5;

int ball_x = 2;
int ball_y = 6;

int score_left_player = 0;
int score_right_player = 0;

void CleanerScreen() {
    printf("\033[2J");
}

void score();
void draw();

int main() {
    int vector_x = 1;
    int vector_y = 1;

    while (1) {
        draw(left_rocket, right_rocket, ball_x, ball_y);
        char temp = getchar();

        if (temp == 'q' && score_left_player != 2 && score_right_player != 2) {
            printf("%s\n", "\033[3;31mGAME OVER!");
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
        

    //декомпозировать-----------------------------------
    if (ball_y == 1 || ball_y == HEIGHT - 2) {
        vector_y = -(vector_y);
    }
    if (ball_x == 2 && (ball_y == left_rocket - 1 || ball_y == left_rocket || ball_y == left_rocket + 1)) {
        vector_x = -(vector_x);
    }
    if (ball_x == 37 && (ball_y == right_rocket - 1 || ball_y == right_rocket || ball_y == right_rocket + 1)) {
        vector_x = -(vector_x);
    }

    ball_y += vector_y;
    ball_x += vector_x;
    //--------------------------------------------------
    score();
    }
    

    }
}

void draw(int left_rocket, int right_rocket, int ball_x, int ball_y) {
    CleanerScreen();
    for (int y = 0; y < HEIGHT; ++y)
    {
        for (int x = 0; x < WIDTH; ++x)
        {
            if ((y == 0 && x != 0 && x != WIDTH - 1) || (y == HEIGHT - 1 && x != 0 && x != WIDTH - 1))
            {
                printf("-");
            }
            else if (((x == 0 && y != 0 && y != HEIGHT - 1) || (x == WIDTH - 1 && y != 0 && y != HEIGHT - 1)))
            {
                printf("|");
            }
            else if (x == 1 && (y == left_rocket || y == left_rocket + 1 || y == left_rocket + 2))
            {
                printf("X");
            }
            else if (x == WIDTH - 2 && (y == right_rocket || y == right_rocket + 1 || y == right_rocket + 2))
            {
                printf("X");
            }
            else if (x == ball_x && y != 0 && y == ball_y)
            {
                printf("o");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void score() {
if (ball_x < 2) {
    score_right_player++;
    ball_x = 2;
    ball_y = 6;
}

if (ball_x > WIDTH - 1) {
    score_left_player++;
    ball_x = 2;
    ball_y = 6;
}

if (score_left_player == 2) {
    printf("\n\tCONGRATULATION!!! LEFT PLAYER IS WON. SCORE %d : %d\n", score_left_player, score_right_player);
} else if (score_right_player == 21) {
    printf("\n\tCONGRATULATION!!! RIGHT PLAYER IS WON. SCORE %d : %d\n", score_left_player, score_right_player);
}
}
