#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char grid[5][5];
    char word[6];
    int score = 0;
    char rollno[4] = {'0', '7', '5', '3'};
    
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int a = (rand() % 26) + 'a'; 
            grid[i][j] = a;
        }
    }
    for (int i = 0; i < 4; i++) {
        grid[4][i] = rollno[i];
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("Enter your word:\t");
    scanf("%s", word);
    int len = strlen(word);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            if (strncmp(&grid[i][j], word, len) == 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i <= 5 - len; i++) {
                int match = 1;
                for (int k = 0; k < len; k++) {
                    if (grid[i + k][j] != word[k]) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    found = 1;
                    break;
                }
            }
            if (found) {
            break;
            }
        }
    }

    if (found) {
        printf("Your word has been found!\n");
        score++;
    } else {
        printf("Your word was not found.\n");
    }
    printf("your score is: %d",score);
    return 0;
}