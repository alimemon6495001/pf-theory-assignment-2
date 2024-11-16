#include <stdio.h>
#include <math.h>
#include <string.h>

int bTd(int input) {
    int i=0;
    int rem=0;
    while(input>0) {
        int d=input%10;
        rem += pow(2,i)*d;
        input=input/10;
        i++;
    }
    return rem;
}
long dTb(long input) {
    int base=1;
    long binary=0;
    while(input>0) {
        int d=input%2;
        binary += base * d;
        input = input/2;
        base *= 10;
    }
    return binary;
}
void dTh(int input) {
    char hexa[20] = {0,0,0,0,0,0,0,0};
    int i=0;
    while(input>0) {
        int d=input%16;
        if(d<=9) {
            hexa[i]='0'+d;
        }
        else {
            hexa[i]='A'+(d-10);
        }
        input=input/16;
        i++;
    }
    for(int j=i-1;j>=0;j--) {
        printf("%c",hexa[j]);
    }
}
void hTd(char hex[]) {
    int decimalValue = 0;
    int base = 1;
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];
        int value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0'; 
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input\n");
        }

        decimalValue += value * base;
        base *= 16;
    }
    printf("%d ",decimalValue);

}
void hTb(char hex[]) {
    int decimalValue = 0;
    int base = 1;
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];
        int value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0'; 
        } else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        } else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        } else {
            printf("Invalid hexadecimal input\n");
        }

        decimalValue += value * base;
        base *= 16;
    }
    int binary = dTb(decimalValue);
    printf("%d ",binary);
}
void bTh(int input) {
    int decimal = bTd(input);
    dTh(decimal);
}
int main()  {
    printf("number system converter\n1.decimal to binary\n2.binary to decimal\n3.decimal to hexa\n4.hexa to decimal\n");
    printf("5.binary to hexa\n6.hexa to binary");
    int n;
    printf("\n enter your choice:\t");
    scanf("%d",&n);
    int input;
    char input1[30];
    printf("\n\n");
    switch(n) {
    	case 1:
    		printf("enter your decimal value:\t");
    		scanf("%d",&input);
    		printf("the result is: %d",dTb(input));
    		break;
        case 2:
            printf("enter your binary value:\t");
            scanf("%d",&input);
            printf("the result is: %d",bTd(input));
            break;
        case 3:
            printf("enter your decimal value:\t");
            scanf("%d",&input);
            dTh(input); 
            break;
        case 4: 
            printf("enter your hexa value:\t");
            scanf("the result is: %s",input1);
            hTd(input1);
            break;
        case 5:
            printf("enter your binary number:\t");
            scanf("the result is: %d",&input);
            bTh(input);
            break;
        case 6:
            printf("enter your hexa value:\t");
            scanf("the result is : %s",input1);
            hTb(input1);
            break;
	}
}