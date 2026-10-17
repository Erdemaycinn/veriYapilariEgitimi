#include "stdlib.h"
#include "string.h"
#include <stdalign.h>
#include <stdio.h>

typedef struct dynamicStringArray {
    int size;
    int curr;
    char *ptr;
} dSArray;

int dSArrayGrow(dSArray *arr) {
    char *nptr;

    if (!arr->size) {
        arr->size = 1;
        nptr = malloc(sizeof(char));
    } else {
        nptr = realloc(arr->ptr, arr->size * 2 * sizeof(char));
    }
    if (nptr) {
        arr->ptr = nptr;
        return 1;
    }
    return 0;
}

int dSArrayAppendString(dSArray *arr, char *string) {
    while (arr->size < arr->curr + sizeof(char)) {
        if (!dSArrayGrow(arr))
        return 0;
    }

    memcpy(arr->ptr, string, strlen(string));
    return 1;
}

dSArray* newDSArray(){
    dSArray* arr = malloc(sizeof(dSArray));
    if(!arr)
        return arr;
    arr->size = 0;
    arr->curr = 0;
    arr->ptr = (char*) NULL;
    return arr;
}

int main() { 
    dSArray* myArray = newDSArray();
    printf("bu benim ilk dinamik string arrayim! suan hicbirsey yazmiyor: '%s'\n",myArray->ptr);
    dSArrayAppendString(myArray, "merhaba dunya");
    printf("bu benim ilk dinamik string arrayim! suan birseyler yaziyor: '%s'\n",myArray->ptr);
}
