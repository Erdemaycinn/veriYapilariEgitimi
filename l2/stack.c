#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

// Stack (yığın): LIFO (Last In First Out) mantığı ile çalışır.
// Son eklenen eleman ilk çıkarılır. Altyapı olarak linked list kullanılır.
typedef struct stack{
    linkedList* liste; // elemanları tutan linked list. tepe (top) listenin başlangıcıdır.
}stack;

// yeni, boş bir stack oluşturur.
stack* newStack();

// stack'in tepesine eleman ekler. başarılıysa 1, değilse 0 döner.
int push(stack* s, int degisken);

// stack'in tepesindeki elemanı çıkarır ve değerini döner.
int pop(stack* s);

// stack'in tepesindeki elemanı çıkarmadan değerini döner.
int peek(stack* s);

// stack boşsa 1, değilse 0 döner.
int isStackEmpty(stack* s);

// stack'teki eleman sayısını döner.
int stackSize(stack* s);

// stack'i ve içindeki tüm elemanları serbest bırakır.
void freeStack(stack* s);
