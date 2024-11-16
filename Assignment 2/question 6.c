#include <stdio.h>

int findWinningMove(int N) {

    if (N % 5 == 0) {
        return -1;
    }
    
    return N % 5;
}

int main() {
    int N;
    printf("Enter the total number of matchsticks: ");
    scanf("%d", &N);

    int result = findWinningMove(N);

    if (result == -1) {
        printf("It's impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on the first turn to guarantee a win.\n", result);
    }

    return 0;
}