#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include "sort.h"

int main(int argc , char *argsv[]){
    FILE *f = fopen(argsv[1] , "r"); 
    int arr[5] = {0 , 0 , 0 , 0 , 0}; 
    for(int i = 0 ; i < 5 ; i++){
        fscanf(f , "%d" , &arr[i]); 
    }
    fclose(f); 
    for(int i = 0 ; i < 5 ; i++){
        printf("%d" , arr[i]); 
    }
    sort(arr , 5); 
    for(int i = 0 ; i < 5 ; i++){
        printf("%d" , arr[i]); 
    }
    return 0;
}