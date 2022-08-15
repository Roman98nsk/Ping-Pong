#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int score_left_player = 0, score_right_player = 0, score_part_left_player = 0, score_part_right_player = 0, score_difference = 0, part = 1;

    do {
        srand(time(NULL));
        score_left_player = 0 + rand()%12;
        score_right_player = 0 + rand()%12;
        score_difference = abs(score_left_player - score_right_player);

        sleep(2);

        if (score_left_player != 11 || score_right_player != 11) {
            printf("\t\tGame %d"
            "\n\t\t\033[1:32m%d : %d\033[0m"
            "\n    \"Left_player\" : \"Right_player\"\n"
            "\t%d \t\t    %d\n", part, score_left_player, score_right_player, score_part_left_player, score_part_right_player);
        }

        if ((score_left_player == 11 || score_left_player > 11) && score_difference >= 2) {
            printf("\n\033[1;32mLEFT PLAYER WON GAME!\nGAME SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
            part++;
            score_part_left_player++;
        } else if ((score_right_player == 11 || score_right_player > 11) && score_difference >= 2) {
            printf("\n\033[1;32mRIGHT PLAYER WON GAME!\nGAME SCORE %d : %d.\033[0m\n\n", score_left_player, score_right_player);
            part++;
            score_part_right_player++;
        }

        if (part > 7) {
            printf("\033[1;32mTOTAL SCORE: %d : %d\033[0m\n", score_part_left_player, score_part_right_player);
            if (score_part_left_player > score_part_right_player) {
                printf("\n\033[1;32mCONGRATULATION!!! LEFT PLAYER CHAMPION!\033[0m\n\n");
            } else {
                printf("\n\033[1;32mCONGRATULATION!!! RIGHT PLAYER CHAMPION!\033[0m\n\n");
            }
            return 0;
        }
    } while ((score_left_player != 12 || score_right_player != 12) || score_difference < 2);
return 0;
}
