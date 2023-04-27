#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

void* runner(void* params); 

typedef struct t{
    int a; 
} t; 

int main(int argc , char* argv[]){ 
    int* a = (int*)malloc(sizeof(int*)); 
    *a = 10; 
    pthread_t thread; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 
    pthread_create(&thread , &attr , runner , (void*) a); 
    void* res; 
    pthread_join(thread , &res);
    int ans = *((int*)res); 
    printf("Res : %d" , ans);  
    return 0; 
}

void* runner(void* params){
    int a = *((int*) params); 
    int* b = (int*)malloc(sizeof(int*)); 
    *b = 100; 
    printf("%d \n" , a); 
    pthread_exit((void*) b); 
}