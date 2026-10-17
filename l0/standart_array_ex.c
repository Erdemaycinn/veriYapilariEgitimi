#include <stdio.h>

void main(){
  char arr[10];

  for(int i; i<=10; i++){
    printf("\ncurrent array is %s \nenter a char\n> ",arr);
    arr[i] = getchar();
    getchar();
  }
}
