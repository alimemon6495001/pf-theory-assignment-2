#include <stdio.h>
#include <string.h>

int main() {
    int n,length,c,b;
    printf("enter no of words: ");
    scanf("%d",&n);
    int flag[n];
    for(int i=0;i<10;i++) {
        flag[i]=0;
    }
    char arr[n][30];
    int count[100][100];
    for(int i=0;i<n;i++) {
        printf("enter word#%d\t",i+1);
        scanf(" %s",arr[i]);
    } 
    for(int i=0;i<n;i++) {
        length = strlen(arr[i]);
        for(int j=0;j<length;j++) {
            count[i][j] =0;
        }
    }
    for(int i=0;i<n;i++) {
        length = strlen(arr[i]);
        for(int j=0;j<length;j++) {
            c = arr[i][j];
            count[i][c-97]++;
        }
    }
    printf("\n");
    printf("the updated words are: \n");
    for(int i=0;i<n;i++) {
        length=strlen(arr[i]);
        for(int j=0;j<length;j++) {
            c=arr[i][j];
            if(count[i][c-97]>0) {
                printf("%c",arr[i][j]);
                count[i][c-97]=0;
            }      
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<n;i++) {
        length = strlen(arr[i]);
        for(int j=0;j<length;j++) {
            c = arr[i][j];
            count[i][c-97]++;
            if(count[i][c-97]>1) {
                flag[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++) {
        length=strlen(arr[i]);
        if(flag[i]>0) {
                printf("in word# %d\n",i+1);
            }
        for(int j=0;j<length;j++) {
            c=arr[i][j];
            if(count[i][c-97]>1) {
                printf("'%c' was removed %d times\n",arr[i][j],count[i][c-97]-1);
                count[i][c-97]=0;
            }
        }
        printf("\n\n");
    }
}