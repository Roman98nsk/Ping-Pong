#include <stdio.h>

void print() {
    printf("o");
}

int main () {
    //int n;
    int count = 0;

    while(count != 5) {
        print();
        count++;
    }
    printf("\n");
    
    /*printf("\n1 - continue, 0 - quit\n");
    scanf("%d", &n);
    if (n == 1){
        main();
    }*/
return 0;
}
