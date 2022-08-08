#ifndef PONG_FUNCTIONS_H
#define PONG_FUNCTIONS_H

void CleanerScreen();
void draw(int left_rocket, int right_rocket, int ball_x, int ball_y, int HEIGHT, int WIDTH);
int score(int score_left_player, int score_right_player);
int management(int left_rocket, int right_rocket, int HEIGHT);
int game(int ball_x, int ball_y, int HEIGHT, int WIDTH, int vector_x, int vector_y, int left_rocket, int right_rocket,
                                                                            int score_right_player, int score_left_player);
#endif