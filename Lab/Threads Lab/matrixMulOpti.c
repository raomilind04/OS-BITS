#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


#define N 2

typedef struct index{
    int row; 
    int col;
} idx; 

int a[N][N] = {{1 , 2} , {1 , 2}}; 
int b[N][N] = {{1 , 2} , {1 , 2}}; 
int c[N][N] = {{0 , 0} , {0 , 0}};

void* runner(void* params); 

int main(){
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

    pthread_t threads[N][N]; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr);

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            idx* id = (idx *)malloc(sizeof(int)*2);
            id->row = i; 
            id->col = j;
            pthread_create(&threads[i][j] , &attr , runner , (void *)id); 
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            pthread_join(threads[i][j] , NULL);
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            printf("%d  " , c[i][j]); 
        }
        printf("\n"); 
    }
    return 0; 
}

void* runner(void* params){
    idx* temp = (idx*) params; 
    for(int i = 0 ; i < N ; i++){
            c[temp->row][temp->col] += (a[temp->row][i]*b[i][temp->col]); 
    }
    pthread_exit(0); 
}