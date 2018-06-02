#include <stdio.h>

void swap(int *pj, int *pjprev){
     int temp = *pj;
    *pj = *pjprev;
    *pjprev = temp;
}

void main(){
    int arr[] = {4,3,2,5,1,4343,546565,2121,5657,0};
    int len = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i < len; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }

    for(int i=0; i < len; i++){
        printf("%d \n", arr[i]);
    }
} 