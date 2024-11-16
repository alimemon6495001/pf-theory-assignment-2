#include <stdio.h>

int main() {
    char move;
    int start = 1;
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    
    int posX = 4; 
    int posY = 4;

    printf("Enter your move:\nFor up (w)\nFor down (s)\nFor left (a)\nFor right (d)\nFor quit (q)\n");

    while (start) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }

        printf("Enter your move: ");
        scanf(" %c", &move); 

        switch (move) {
            case 'w':
                if (posY > 0 && (grid[posY - 1][posX] == 'I' || grid[posY - 1][posX] == ' ')) {
                    grid[posY - 1][posX] = 'P';
                    grid[posY][posX] = ' ';
                    posY--;
                } else {
                    printf("Invalid move\n");
                }
                break;
            case 's':
                if (posY < 4 && (grid[posY + 1][posX] == 'I' || grid[posY + 1][posX] == ' ')) {
                    grid[posY + 1][posX] = 'P';
                    grid[posY][posX] = ' ';
                    posY++;
                } else {
                    printf("Invalid move\n");
                }
                break;
            case 'a':
                if (posX > 0 && (grid[posY][posX - 1] == 'I' || grid[posY][posX - 1] == ' ')) {
                    grid[posY][posX - 1] = 'P';
                    grid[posY][posX] = ' ';
                    posX--;
                } else {
                    printf("Invalid move\n");
                }
                break;
            case 'd':
                if (posX < 4 && (grid[posY][posX + 1] == 'I' || grid[posY][posX + 1] == ' ')) {
                    grid[posY][posX + 1] = 'P';
                    grid[posY][posX] = ' ';
                    posX++;
                } else {
                    printf("Invalid move\n");
                }
                break;
            case 'q': 
                start = 0;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }

    return 0;
}
