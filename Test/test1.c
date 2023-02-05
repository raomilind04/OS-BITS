#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int main(){
    if(fork() == 0){
        printf("%d is the child of %d \n" , getpid() , getppid()); 
    }else{
        printf("%d is the parent of %d \n" , getpid() , fork()); 
    }
}
