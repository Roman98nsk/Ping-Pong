#include <stdio.h>

int HEIGHT = 25;
int WIDTH = 80;
int left_rocket = 11;
int right_rocket = 11;

int ball_x = 39;
int ball_y = 12;
int vector_x = 1;
int vector_y = 1;

int score_left_player = 0;
int score_right_player = 0;

void draw();

int main(){
char temp;
while (1){
temp = getchar();
if (temp != '\n'){
draw(left_rocket, right_rocket, ball_x, ball_y);
switch (temp) {
case 'a':
((left_rocket - 1) != 0) ? (left_rocket -= 1) : left_rocket; break;
case 'z':
((left_rocket + 2)!= HEIGHT - 2) ? (left_rocket += 1) : left_rocket; break;
case 'k':
((right_rocket - 1)!= 0) ? (right_rocket -= 1) : right_rocket; break;
case 'm':
((right_rocket + 2)!= HEIGHT - 2) ? (right_rocket += 1) : right_rocket; break;
}


if(ball_y == 1 || ball_y == HEIGHT - 2)
vector_y = -(vector_y);
if (ball_x == 3 && (ball_y == left_rocket - 1 || ball_y == left_rocket || ball_y == left_rocket + 1)) )
vector_x = -(vector_x);
if (ball_x == 77 && (ball_y == right_rocket - 1 || ball_y == right_rocket || ball_y == right_rocket + 1)))
vector_x = -(vector_x);

ball_y += vector_y;
ball_x += vector_x;

if (ball_x < 2) {
score_right_player++;
ball_x = 39;
ball_y = 12;
}
if (ball_x > WIDTH - 1) {
score_left_player += 1;
ball_x = 39;
ball_y = 12;
}
}
if (score_left_player == 2) {
printf("\n\tCONGRATULATION!!! LEFT PLAYER IS WON. SCORE %d : %d.", score_left_player, score_right_player);
return 1;
} else if (score_right_player == 21) {
printf("\n\tCONGRATULATION!!! PLAYER TWO IS WON BY %d TO %d.", score_left_player, score_right_player);
return 1;
}

}

return 0;
}

void draw(int left_rocket, int right_rocket, int ball_x, int ball_y){
for (int y = 0; y < HEIGHT; ++y) {
for (int x = 0; x < WIDTH; ++x) {
if ((y == 0 && x != 0 && x != WIDTH - 1) || (y == HEIGHT - 1 && x != 0 && x != WIDTH - 1)) {
printf("-");
} else if (((x == 0 && y != 0 && y != HEIGHT -1) || (x == WIDTH - 1 && y != 0 && y != HEIGHT -1))) {
printf("|");
} else if (x == 40 && y != 0 && y != HEIGHT -1) {
printf("|");
} else if(x == 1 && (y == left_rocket || y == left_rocket + 1 || y == left_rocket + 2)){
printf("X");
} else if(x == 78 && (y == right_rocket || y == right_rocket + 1 || y == right_rocket + 2)){
printf("X");
} else if(x == ball_x && y != 0 && y == ball_y){
printf("*");
} else {
printf(" ");
}
}
printf("\n");
}
}