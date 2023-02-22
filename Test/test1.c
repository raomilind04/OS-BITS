#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<assert.h>

int main(int argc , char* argsv[]){
    int arr[5] = {1 , 2 , 3 , 4 , 5}; 
    FILE* f; 
    f = fopen(argsv[1] , "w"); 
    for(int i = 0 ; i < 5 ; i++){
        fprintf(f , "%d " , arr[i]); 
    }
    fclose(f); 
    f = fopen(argsv[1] , "r"); 
    int output[5] = {0 , 0 , 0 , 0 , 0}; 
    for(int i = 0 ; i < 5 ; i++){
        fscanf(f , "%d" , &output[i]);  
    }
    for(int i = 0 ; i < 5 ; i++){
        printf("%d " , output[i]); 
    }
    return 0; 
}
