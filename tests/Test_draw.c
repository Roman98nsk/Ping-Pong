#include <stdio.h>
#include <sys/ioctl.h>

int mt_getscreensize(int *rows, int *cols);

int main() {
int HEIGHT = 0, WIDTH = 0, left_rocket = 0, right_rocket = 0, ball_x = 0, ball_y = 0, tmp = 0, tmp2 = 0;

mt_getscreensize(&tmp, &tmp2);

printf("Input HEIGHT: \n");
scanf("%d", &HEIGHT);

printf("Input WIDTH: \n");
scanf("%d", &WIDTH);

if (HEIGHT < 5 || WIDTH < 5 || HEIGHT >= tmp || WIDTH >= tmp2) {
    printf("Incorrect input!\n");
    return 0;
}

printf("Input coordinate \"X\" left rocket: \n");
scanf("%d", &left_rocket);

printf("Input coordinate \"X\" right rocket: \n");
scanf("%d", &right_rocket);

if ((left_rocket < 1 || left_rocket > HEIGHT - 4) || (right_rocket < 1 || right_rocket > HEIGHT - 4)) {
    printf("Incorrect input!\n");
    return 0;
}

printf("Input coordinate \"X\" ball: \n");
scanf("%d", &ball_x);

printf("Input coordinate \"Y\" ball: \n");
scanf("%d", &ball_y);

if ((ball_x < 2 || ball_x > WIDTH - 3) || (ball_y < 2 || ball_y > HEIGHT - 2)) {
    printf("Incorrect input!\n");
    return 0;
}

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

int mt_getscreensize(int *rows, int *cols) {
  struct winsize ws;
  ioctl(1, TIOCGWINSZ, &ws);
  *rows = ws.ws_row;
  *cols = ws.ws_col;

  printf("Height terminal = %d, Width terminal = %d\n", *rows, *cols);

  return 0;
}
