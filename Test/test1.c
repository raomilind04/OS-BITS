#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

void copy(int a[], int n, int* c) { int j;
c = (int *) malloc(n*sizeof(int));
for (j=0; j<n; j++) c[j] = a[j]; }


int main(){
    int arr[5]= {1,6,3,4,5}; 
    int var = 5; 
    int *c = &var; 
    copy(arr,5,c); 
    printf("%d", c[2]); 
    return 0; 
}
