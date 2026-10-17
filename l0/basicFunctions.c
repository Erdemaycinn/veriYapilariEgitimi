#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listAllElements(int* arr, int a){
    for (int i=0 ; i< a; i++){
        printf("\t%d. : %d\n",i,arr[i]);
    }
}
int main(){
    // malloc(size_t size);
    // realloc(void *ptr, size_t size)
    // calloc(1, sizeof(int));

    int* arr1 = malloc(10 * sizeof(int));
    arr1[0]=16;
    printf("\n malloc ile olusturuldugunda (arr1: %p)\n",arr1);
    listAllElements(arr1, 10);


    // normalde rastgele degerler gelebilirdi, ancak muhtemelen* isletim sistemi dolayisiyla processe bos sayfalar verildi


    int* arr2 = calloc(10 ,sizeof(int));

    printf("\n calloc ile olusturuldugunda (arr2: %p)\n",arr2);
    listAllElements(arr2, 10);


    // calloc her seferinde bos memoryi garantiler


    arr1 = realloc(arr1, sizeof(int)*20);
    printf("\n realloc ile buyutuldugunde (arr1: %p)\n",arr1);
    listAllElements(arr1, 20);




    printf("\n\n\n [] operandi aslinda icerisindeki sayiyi pointera ekleyip degeri yazmakdan baska bisey yapmaz:");
    printf("\n\n [] operandi ile arr1 in ilk elemani:\n\t%d",arr1[0]);
    printf("\n\n dogrudan adresi ile arr1 in ilk elemani:\n\t%d\n\n",*arr1);
}
