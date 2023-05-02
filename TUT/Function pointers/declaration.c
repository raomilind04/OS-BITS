#include <stdio.h>


void print(int a){
    printf("%d\n" , a); 
}
void print2(int a , int b){
    printf("a : %d\n" , a); 
    printf("b : %d\n" , b); 
}
int main(){
    void (*print_ptr)(int) = &print; 
    (*print_ptr)(10); 
    void (*print2_ptr)(int , int) = &print2; 
    (*print2_ptr)(100 , 200); 
    return 0; 
}