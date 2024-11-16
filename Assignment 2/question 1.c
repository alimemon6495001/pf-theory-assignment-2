 #include <stdio.h>

int main() {
    int arr[5];
    int n = 5;
    int i, first, second;

   
    printf("Enter 5 elements in the array (value must be < 9999):\n");
    for(i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
       
        if(arr[i] >= 9999) {
            printf("Value must be less than 9999. Try again.\n");
            return 1;
        }
    }

   
    first = second = 9999;  

    
    for(i = 0; i < n; i++) {
        if(arr[i] < first) {
            second = first;  
            first = arr[i];  
        } else if(arr[i] < second && arr[i] != first) {
            second = arr[i]; 
        }
    }

   
    if(second != 9999) {
        printf("The Second smallest element in the array is: %d\n", second);
    } else {
        printf("No second smallest element found.\n");
    }

    return 0;
}