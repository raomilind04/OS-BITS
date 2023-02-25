#include<stdio.h>
#include<stdlib.h>

struct heap{
    int size; 
    int* firstFree; 
    int used; 
    int* arr; 
}; 

typedef struct heap h; 

extern void createHeap(int size , h* h1); 

extern void insert(int size , h* h1); 

extern void clear(h* h1); 

extern void delete(h* h1); 