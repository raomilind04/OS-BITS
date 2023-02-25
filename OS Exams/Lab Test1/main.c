#include<stdio.h>
#include<stdlib.h>
#include "ops.h"

int main(int argsc , char* argsv[]){
    int size = atoi(argsv[1]); 
    if(size > 100 || size < 20){
        perror("Invalid Size"); 
        exit(1); 
    }

    h* h1 = (h*)malloc(sizeof(h));

    createHeap(size , h1); 
    insert(50 , h1); 
    insert(40 , h1); 
    clear(h1); 
    insert(50 , h1);
    delete(h1); 
    return 0; 
}