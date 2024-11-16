#include <stdio.h>
#include <string.h>

void makeArray(int word[][26],char arr[][30],int n) {
    int a;
    for(int i=0;i<n;i++) {
        for(int j=0;j<26;j++) {
            word[i][j]=0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(arr[i]); j++) {
            char ch = arr[i][j];
            word[i][ch - 'a'] = 1;
        }
    }
}

int checkArray(int word[][26],int n,int n1) {
    for(int j=0;j<26;j++) {
        if(word[n][j]!=word[n1][j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n,flag;
    printf("enter number of words:\t");
    scanf("%d",&n);
    char input[n][30];
    for(int i=0;i<n;i++) {
        scanf("%s",input[i]);
    }
    int word[n][26];
    makeArray(word,input,n);
    printf("\n");
    int result[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = -1; 
        }
    }
    for (int i = 0; i < n; i++) {
        int count = 0; 
        result[i][count] = i; 
        count++;
        for (int j = 0; j < n; j++) {
            if (i != j && checkArray(word, i, j)) {
                result[i][count] = j;
                count++; 
            }
        }
        while (count < n) {
            result[i][count] = -1;
            count++;
        }
    }
    printf("\n");
    int var=1;
    for(int i=0;i<n;i++) {
        flag=0;
        int j=0;
        while(j<n) {
            if(result[i][j]>-1 && input[result[i][j]][0]!='0') {
                printf("category # %d:\t",var);
                var++;
                break;
            }
            j++;
            break;
        }
        for(int j=0;j<n;j++) {
            if(result[i][j]>-1 && input[result[i][j]][0]!='0') {
                printf("%s ",input[result[i][j]]);
                input[result[i][j]][0]='0';
                flag=1;
            }
        }
        if(flag) {
            printf("\n");
        }
    }
}