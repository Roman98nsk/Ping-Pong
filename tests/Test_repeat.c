#include <stdio.h>
#include <unistd.h>

int main() {
    int start = 0, part = 1;
   
    do {
        printf("For start press '1': ");
        if (scanf("%d", &start) && (start == 1 || start == 0)) {
            if (start == 1) {
                for (int i = 0; i < 11; i++) {
                    sleep(1);
                    printf("o\n");
                }
                printf("Part %d complite\n", part++);
            }
        } else {
            return 0;
        }
    } while (start != 0);
    return 0;
}
