#include <stdio.h>

// by default extern 
int get_global();

// some where => handle when .o files are combined
// var are not extern by default
// storage class
extern int global;

int main() {
    int val = get_global();
    printf("%d\n", val);

    global += 500;

    val = get_global();
    printf("%d\n", val);
}