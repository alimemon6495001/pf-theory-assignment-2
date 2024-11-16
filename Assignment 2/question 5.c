#include <stdio.h>


int main() {
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    int num[n];
    int hi = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        if (num[i] > hi) {
            hi = num[i];
        }
    }

    int indicator[n][hi+1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= hi; j++) {
            indicator[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < num[i]; j++) {
            indicator[i][j]++;
        }
    }
    printf("\n");
    for(int i=0;i<n;i++) {
        printf("value # %d:\t",i+1);
        for(int j=0;j<num[i];j++) {
            if(indicator[i][j]>0) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    for(int j=hi;j>=0;j--) {
        for(int i=0;i<n;i++) {
            if(indicator[i][j]>0) {
                printf("*  ");
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for(int i=0;i<n;i++) {
        printf("%d  ",num[i]);
    }
    printf("\n");
     return 0;
}