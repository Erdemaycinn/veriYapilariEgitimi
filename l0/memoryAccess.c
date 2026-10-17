#include "stdio.h"
int main(){
    int a=16;
    int* var=&a;

    printf("\n\t%d",   var[0]);
    printf("\n\t%d",   *var);
    printf("\n\t%d\n", 0[var]);
    return 1;
}
