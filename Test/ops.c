#include<stdio.h>
#include<stdlib.h>
#include "ops.h"

void createHeap(int size , h* h1){
    int* temp = (int*)malloc(sizeof(int)*size); 
    h1->arr = temp;
    h1->size = size; 
    h1->used = 0; 
    h1->firstFree = temp;  
}

void insert(int size , h* h1){
    int free = h1->size - h1->used; 
    if(size > free){
        perror("Not enough Space"); 
        exit(1); 
    }
    h1->firstFree += size;
    h1->used += size;
}

void clear(h* h1){
    int size = h1->size; 
    free(h1->arr); 
    int* temp = (int*)malloc(sizeof(int)*size); 
    h1->arr = temp; 
    h1->firstFree = temp; 
    h1->used = 0;
}

void delete(h* h1){
    free(h1); 
}
