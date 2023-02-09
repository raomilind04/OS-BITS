#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int main(){
    FILE *f ; 
    f = fopen("/Users/milindrao/Desktop/college/3-2/OS/Code/Test/test.txt" , "w"); 
    if(f == NULL){
        printf("Error"); 
        return 0; 
    }
    int n ; 
    scanf("%d" , &n);
    fprintf(f , "%d" , n); 
    fclose(f); 
    int  num;  
    f = fopen("/Users/milindrao/Desktop/college/3-2/OS/Code/Test/test.txt" , "r"); 
    fscanf(f , "%d" , &num);
    fclose(f); 
    printf("Found : %d" , num);  
}
