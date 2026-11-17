#include <stdio.h>
#include "linkedList.h"

static void yazdir(linkedList* list){
    printf("[");
    for (int i = 0; i < list->boyut; i++)
        printf(i ? " %d" : "%d", getElement(list, i));
    printf("] boyut=%d\n", list->boyut);
}

int main(){
    linkedList* list = newLinkedList();
    addToStart(list, 8);
    addToEnd(list, 6);
    addToIndex(list, 1, 16);
    yazdir(list);                 // [8 16 6]

    reverseLinkedList(list);
    yazdir(list);                 // [6 16 8]

    editValue(list, 2, 99);
    yazdir(list);                 // [6 16 99]

    printf("popEnd: %d\n", popEnd(list));       // 99
    printf("deleteFrom(1): %d\n", deleteFrom(list, 1)); // 16
    printf("popStart: %d\n", popStart(list));   // 6
    yazdir(list);                 // [] boyut=0

    reverseLinkedList(list);      // boş listede çökmemeli
    yazdir(list);

    // dolu bir listeyi serbest bırakmayı test ederiz.
    for (int i = 0; i < 5; i++)
        addToEnd(list, i);
    yazdir(list);                 // [0 1 2 3 4]
    freeLinkedList(list);
    return 0;
}
