#include<pthread.h> 
#include<stdio.h>
#include<stdlib.h>

int final[100]; 

void *Th1(void *param);
void *Fibo2(void *param);
void *Fibo3(void *param);
void *Print(void *param);
void *Fibo(void *param); 

typedef struct pass{
    int idx; 
    int val; 
} pass; 

typedef struct ipass{
    int input_value; 
    int t_num; 
} ipass; 

int main(int argc , char* args[]){
    int n;
    pthread_t input_thread; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr);
    void* params;  
    pthread_create(&input_thread , &attr , Th1 , params); 
    void* input_value; 
    pthread_join(input_thread , &input_value);
    n = *((int*) input_value); 

    pthread_t T2; 
    pthread_t T3;
    pthread_attr_init(&attr); 
    ipass* temp = (ipass*)malloc(sizeof(ipass*)); 
    temp->input_value = n; 
    temp->t_num = 2; 
    pthread_create(&T2 , &attr , Fibo , (void*) temp); 
    ipass* temp2 = (ipass*)malloc(sizeof(ipass*)); 
    temp2->input_value = n; 
    temp2->t_num = 3;
    pthread_create(&T3 , &attr , Fibo , (void*) temp2); 
    pthread_join(T2 , NULL); 
    pthread_join(T3 , NULL); 
    free(temp); 
    free(temp2); 
    printf("N fib numbers : ");
    for(int i = 0 ; i < n ; i++){ 
        printf("%d " , final[i]); 
    }
    return 0; 
}

void *Th1(void* params){
    int* input_value = (int*)malloc(sizeof(int*)); 
    printf("Input an Number : "); 
    int in; 
    scanf("%d" , &in);
    *input_value = in; 
    pthread_exit((void*) input_value);  
}

void *Fibo(void *param){
    ipass* temp = (ipass*) param; 
    int t_num = temp->t_num; 
    int n = temp->input_value; 
    int fib[n]; 
    if(n > 1){
        fib[0] = 0;
        if(t_num == 2){
            pthread_t even; 
            pthread_attr_t attr; 
            pthread_attr_init(&attr);
            pass* params = (pass*)malloc(sizeof(pass)); 
            params->idx = 0; 
            params->val = fib[0]; 
            pthread_create(&even , &attr , Print , params); 
            pthread_join(even , NULL);
        }
    }
    if(n > 2){
        fib[1] = 1; 
        if(t_num == 3){
            pthread_t odd; 
            pthread_attr_t attr; 
            pthread_attr_init(&attr); 
            pass* params = (pass*)malloc(sizeof(pass)); 
            params->idx = 1; 
            params->val = fib[1]; 
            pthread_create(&odd , &attr , Print , params); 
            pthread_join(odd , NULL); 
            free(params); 
        }
    }
    for(int i = 2 ; i < n ; i++){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]%2 != 0 && t_num == 2){
            pthread_t odd; 
            pthread_attr_t attr; 
            pthread_attr_init(&attr); 
            pass* params = (pass*)malloc(sizeof(pass)); 
            params->idx = i; 
            params->val = fib[i]; 
            pthread_create(&odd , &attr , Print , params); 
            pthread_join(odd , NULL); 
            free(params);
        }else if(fib[i]%2 == 0 && t_num == 3){
            pthread_t odd; 
            pthread_attr_t attr; 
            pthread_attr_init(&attr); 
            pass* params = (pass*)malloc(sizeof(pass)); 
            params->idx = i; 
            params->val = fib[i]; 
            pthread_create(&odd , &attr , Print , params); 
            pthread_join(odd , NULL); 
            free(params);
        }
    }
    pthread_exit(0); 
}

void *Print(void *param){
    pass* temp = (pass*)param; 
    int idx = temp->idx; 
    int val = temp->val; 
    final[idx] = val; 
    printf("Idx : %d || Val : %d\n", idx , val); 
    pthread_exit(0);
}