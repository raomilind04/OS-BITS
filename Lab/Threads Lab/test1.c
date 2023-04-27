#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int sum; 
void *runner(void *params); 

int main(int argc , char* argv[]){
    pthread_t tid; 
    pthread_attr_t attr;
    pthread_attr_init(&attr); 
    int val; 
    pthread_attr_getdetachstate(&attr , &val); 
    if(val != PTHREAD_CREATE_JOINABLE){
        pthread_attr_setdetachstate(&attr , PTHREAD_CREATE_JOINABLE); 
    }
    void* ret;
    pthread_create(&tid , &attr , runner , argv[1]);  
    pthread_join(tid , &ret);
    printf("Ans : %d\n" , *((int*)ret)); 
    printf("%d \n" , sum); 
    printf("End of main thread \n"); 
}

void* runner(void* params){
    // int num1 = atoi(params); 
    // sum = 0; 
    // for(int i = 1 ; i <= num1 ; i++){
    //     sum += i; 
    // }
    int* a = (int*)malloc(sizeof(int*)); 
    *a = 100; 
    printf("%d \n" , a); 
    printf("Exiting the thread %lu \n" , pthread_self()); 
    pthread_exit((void*) a); 
}

