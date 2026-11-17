#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    void* siradaki; // next olarak isimlendirilir, bir node pointeridir.
    int deger;      // payload, data, variable olarak isimlendirilebilir.
}node;

typedef struct linkedList{
    node* baslangic; // head
    int boyut;       // size
}linkedList;

linkedList* newLinkedList();

int  getElement(linkedList* list, int index);
int  addToStart(linkedList* list, int degisken);
int  addToIndex(linkedList* list, int index, int degisken);
int  addToEnd(linkedList* list, int degisken);
int  popStart(linkedList* list);
int  deleteFrom(linkedList* list, int index);
int  popEnd(linkedList* list);
int  editValue(linkedList* list, int index, int degisken);
void reverseLinkedList(linkedList* list);
void freeLinkedList(linkedList* list);

#endif // LINKEDLIST_H
