#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


// Constants
#define MAX_SIZE 2
#define N 2

// Thread runner
void* runner(void* params); 

// Global Matrix 
int a[N][N] = {{1 , 2} , {1 , 2}}; 
int b[N][N] = {{1 , 2} , {1 , 2}}; 
int c[N][N] = {{0 , 0} , {0 , 0}};

int main(int argc , char* argv[]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d  " , a[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n");  
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d  " , b[i][j]); 
        }
        printf("\n"); 
    }
    printf("\n");
    pthread_t threads[MAX_SIZE]; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 
    int curr_row = 0; 
    for(int i = 0 ; i < MAX_SIZE ; i++){
        pthread_create(&threads[i] , &attr , runner , (void*)(intptr_t) curr_row);  
        curr_row++; 
    }
    for(int i = 0 ; i < MAX_SIZE ; i++){
        pthread_join(threads[i] , NULL); 
    }
      
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d  " , c[i][j]); 
        }
        printf("\n"); 
    }
}

void* runner(void* params){
    int row = (intptr_t) params;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            c[row][i] += (a[row][j]*b[j][i]);
        }
    }
    pthread_exit(NULL); 
}