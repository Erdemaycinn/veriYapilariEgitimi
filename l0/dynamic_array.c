#include <stdlib.h>
typedef struct dArray{
    int* ptr;
    int size;
    int capacity;
}DARRAY;


DARRAY* newArray(){
    DARRAY* temp = malloc(sizeof(DARRAY));
    temp->size = 0;
    temp->ptr = malloc(sizeof(int)*10);
    temp->capacity = 10;
    return temp;
}

DARRAY* resize(DARRAY* a, int size){
    a = realloc(a, size);
    return a;
}

int main(int argc, char *argv[])
{   
    DARRAY* arr = newArray();
    arr->ptr[0]= 1;

    return 1;
}
