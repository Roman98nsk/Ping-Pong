#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int score_left_player = 0, score_right_player = 0, score_part_left_player = 0, score_part_right_player = 0,
                                                                                    score_difference = 0, part = 1;

    do {
 printf("Input score left player (0, 1, 2): \n");
    scanf("%d", &score_left_player);

    printf("Input score right player (0, 1, 2): \n");
    scanf("%d", &score_right_player);

    if (score_left_player > 2 || score_right_player > 2) {
        printf("Incorrect input!\n");
        return 0;
    }

    sleep(2);
    score_difference = score_left_player - score_right_player;

    if ((score_left_player != 2 || score_right_player != 2) || (abs(score_difference) < 2)) {
        printf("\t       Part %d", part);
        printf("\n\t\t\033[1:32m%d : %d\033[0m", score_left_player, score_right_player);
        printf("\n    \"Left_player\" : \"Right_player\"\n");
    }

    if (score_left_player == 2 && score_part_left_player == 7 && (abs(score_difference) >= 2)) {
        printf("\t.");
        printf("\n\033[1;32mCONGRATULATION!!! LEFT PLAYER IS WON. SCORE %d : %d.\033[0m\n\n", score_part_left_player, score_part_right_player);
        return 0;
    } else if (score_right_player == 2 && score_part_right_player == 7 && (abs(score_difference) >= 2)) {
        printf("\t\t\t.");
        printf("\n\033[1;32mCONGRATULATION!!! RIGHT PLAYER IS WON. SCORE %d : %d.\033[0m\n\n", score_part_left_player, score_part_right_player);
        return 0;
    }
    part++;
    } while ((score_left_player != 2 || score_right_player != 2) && (abs(score_difference) < 2) && part != 8);
    
return 0;
}
