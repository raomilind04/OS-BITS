#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define M 5 
#define N 4

void* runner(void* params); 
void* input_thread(void* params); 

int a[5]; 
int b[4]; 
int result[N+M]; 

typedef struct in{
    int ai; 
    int bi; 
} in; 

int main(int argc , char* argv[]){
    pthread_t input; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 
    void* params; 
    pthread_create(&input , &attr , input_thread , params); 
    pthread_join(input , NULL); 
    pthread_t threads[N+M];
    pthread_attr_init(&attr);
    int i = 0;  
    for(; i < M ; i++){
        in* params = (in*)malloc(sizeof(in)); 
        params->ai = i; 
        params->bi = -1; 
        pthread_create(&threads[i] , &attr , runner , (void*) params); 
    }
    for(; i < N+M ; i++){
        in* params = (in*)malloc(sizeof(input)); 
        params->ai = -1; 
        params->bi = i-M;
        pthread_create(&threads[i] , &attr , runner , (void*) params); 
    }
    i = 0; 
    for(; i < M ; i++){
        pthread_join(threads[i] , NULL); 
    }
    for(; i < N ; i++){
        pthread_join(threads[i] , NULL); 
    }

    for(int i = 0 ; i < N+M ; i++){
        printf("%d " , result[i]); 
    }
    return 0; 

}
void* input_thread(void* params){
    printf("A : "); 
    for(int i = 0 ; i < M ; i++){
        scanf("%d" , &a[i]); 
    }
    printf("B: "); 
    for(int i = 0 ; i < N ; i++){
        scanf("%d" , &b[i]); 
    }
    pthread_exit(0); 
}
void* runner(void* params){
    in* temp = (in*) params; 
    int ai = temp->ai; 
    int bi = temp->bi; 
    if(ai != -1){
        if(a[ai] <= b[0]){
            result[ai] = a[ai]; 
            pthread_exit(0); 
        }
        if(a[ai] >= b[N-1]){
            result[ai+N] = a[ai]; 
            pthread_exit(0); 
        }
        for(int i = 1 ; i < N ; i++){
            if(a[ai] >= b[i-1] && a[ai] <= b[i]){
                result[ai+i] = a[ai]; 
                pthread_exit(0); 
            }
        }
    }
    if(bi != -1){ 
        if(b[bi] <= a[0]){
            result[bi] = b[bi]; 
            pthread_exit(0); 
        }
        if(b[bi] >= a[M-1]){
            result[bi+M] = b[bi]; 
            pthread_exit(0); 
        }
        for(int i = 1 ; i < M ; i++){
            if(b[bi] >= a[i-1] && b[bi] <= a[i]){
                result[bi+i] = b[bi]; 
                pthread_exit(0); 
            }
        }
    }  
    pthread_exit(0); 
}