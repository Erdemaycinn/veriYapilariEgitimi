#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

// Queue (kuyruk): FIFO (First In First Out) mantığı ile çalışır.
// İlk eklenen eleman ilk çıkarılır. Altyapı olarak linked list kullanılır.
typedef struct queue{
    linkedList* liste; // elemanları tutan linked list. ön (front) listenin başlangıcı, arka (rear) sonudur.
}queue;

// yeni, boş bir queue oluşturur.
queue* newQueue();

// queue'nun arkasına eleman ekler. başarılıysa 1, değilse 0 döner.
int enqueue(queue* q, int degisken);

// queue'nun önündeki elemanı çıkarır ve değerini döner.
int dequeue(queue* q);

// queue'nun önündeki elemanı çıkarmadan değerini döner.
int front(queue* q);

// queue boşsa 1, değilse 0 döner.
int isQueueEmpty(queue* q);

// queue'daki eleman sayısını döner.
int queueSize(queue* q);

// queue'yu ve içindeki tüm elemanları serbest bırakır.
void freeQueue(queue* q);
