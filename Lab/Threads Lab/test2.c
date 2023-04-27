#include<pthread.h> 
#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>


typedef struct data{
    int curr_count; 
    int* a; 
    int counta; 
    int* b; 
    int countb; 
} data; 

int num1 = 123; 
int num2 = 31; 
void* runner(void* params); 

int main(int argc , char* argv[]){ 
    int temp = num1; 
    int count1 = 0; 
    while(temp > 0){
        count1++; 
        temp = temp/10;  
    }
    int* a = (int*)malloc(sizeof(int)*count1);  
    temp = num1; 
    for(int i = 0 ; i < count1 ; i++){
        a[i] = temp%10; 
        temp = temp/10; 
    }
    temp = num2; 
    int count2 = 0; 
    while(temp > 0){
        count2++; 
        temp = temp/10;  
    }
    int* b = (int*)malloc(sizeof(int)*count2); 
    temp = num2; 
    for(int i = 0 ; i < count2 ; i++){
        b[i] = temp%10; 
        temp = temp/10; 
    }
    int count = count1+count2-1; 
    pthread_t threads[count]; 
    pthread_attr_t attr; 
    pthread_attr_init(&attr); 
    int ans[count]; 
    for(int i = 0 ; i < count ; i++){
        data* params = (data*)malloc(sizeof(data)); 
        params->a = a; 
        params->b = b; 
        params->counta = count1; 
        params->countb = count2; 
        params->curr_count = i; 
        pthread_create(&threads[i] , &attr , runner , (void*) params); 
    }
    void* ret; 
    for(int j = count-1 ; j >= 0 ; j--){
        pthread_join(threads[j] , &ret);
        ans[j] = *((int*) ret); 
    }
    for(int i = 0 ; i < count-1 ; i++){
        int temp = ans[i]; 
        ans[i] = ans[i]%10; 
        ans[i+1] += temp/10; 
    }
    int final = 0; 
    for(int i = count-1 ; i >= 0 ; i--){
        final += (ans[i]*pow(10 , i)); 
    }
    printf("%d" , final); 
    return 0; 
}

void* runner(void* params){
    data* rec = (data*)params; 
    int* a = rec->a; 
    int* b = rec->b; 
    int curr = rec->curr_count; 
    int* ans = (int*)malloc(sizeof(int*)); 
    int ret = 0; 
    int pa = curr; 
    int pb = 0; 
    for(; pb <= curr ; pb++){
        if(pb < rec->countb && pa < rec->counta){
            ret += a[pa]*b[pb];  
        }
        pa--; 
    }
    *ans = ret; 
    pthread_exit((void*) ans);
}