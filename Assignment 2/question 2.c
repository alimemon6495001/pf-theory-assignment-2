#include <stdio.h>

int main() {
    int nw,nc;
    printf("enter number of words:\t");
    scanf("%d",&nw);
    printf("enter length of words:\t");
    scanf("%d",&nc);
    char words[nw][nc+1];
    for(int i=0;i<nw;i++) {
        scanf("%s",words[i]);
    }
    printf("\n\n");
    int count[nw][26];
    for(int i=0;i<nw;i++) {
        for(int j=0;j<26;j++) {
            count[i][j]=0;
        }
    }
    for(int i=0;i<nw;i++) {
        for(int j=0;j<nc && words[i][j] !='\0';j++) {
            int a = words[i][j]-'a';
            count[i][a]++;
        }
    }
    for(int i=0;i<nw;i++) {
        printf("for word#%d {",i+1);
        for(int j=0;j<26;j++) {
            if(count[i][j]>0) {
                printf("'%c' %d, ",j+'a',count[i][j]);
            }
        }
        printf("}\n");
    }
    return 0;
}