#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>



void handler(int signum){
    printf("handler \n"); 
}

int main(){
    signal(SIGINT , SIG_IGN); 
    for(int i = 0 ; i < 5 ; i++){
        printf("%d \n" , i);
        sleep(1); 
    }
    signal(SIGINT , handler); 
    for(int i = 5 ; i < 10 ; i++){
        printf("%d \n" , i); 
        sleep(1); 
    }
    signal(SIGINT , SIG_DFL); 
    for(int i = 10  ; i < 15 ; i++){
        printf("%d \n" , i); 
        sleep(1); 
    }
    return 0; 
}