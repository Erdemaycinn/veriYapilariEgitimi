#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

linkedList* newLinkedList(){
    linkedList* list = malloc(sizeof(linkedList));
    if (list == NULL)
        return NULL;
    list->baslangic = NULL;
    list->boyut = 0;
    return list;
}

// linked list üzerindeki belirli indexdeki veriyi almak için bu fonksiyonu kullanırız.
int getElement(linkedList* list, int index){
    if (index < 0 || index >= list->boyut)
        return 0;
    node* suankiNode = list->baslangic;

    while(index--){
        suankiNode = suankiNode->siradaki;
    }
    return suankiNode->deger;
}

// linked listin başlangıcına eleman ekler.
int addToStart(linkedList* list, int degisken){

    node* suankiNode = malloc(sizeof(node));
    if (suankiNode == NULL)
        return 0;
    suankiNode->deger = degisken;
    suankiNode->siradaki = list->baslangic;
    list->baslangic = suankiNode;
    list->boyut++;
    return 1;
}


int addToIndex(linkedList* list, int index, int degisken){

    if (index < 0 || index > list->boyut)
        return 0;
    if(index == 0)
        return addToStart(list, degisken);

    // eklenecek konumdan bir önceki node'a gideriz.
    node* suankiNode = list->baslangic;
    index--;
    while(index-- > 0){
        suankiNode = suankiNode->siradaki;
    }

    node* yeniNode = malloc(sizeof(node));
    if (yeniNode == NULL)
        return 0;
    yeniNode->deger = degisken;
    yeniNode->siradaki = suankiNode->siradaki;
    suankiNode->siradaki = yeniNode;
    list->boyut++;
    return 1;
}

// linked listi ters çevirir.
void reverseLinkedList(linkedList* list){
    node* onceki = NULL;
    node* suankiNode = list->baslangic;

    while (suankiNode != NULL) {
        node* sonraki = suankiNode->siradaki; // sonraki node'u kaybetmemek için saklarız.
        suankiNode->siradaki = onceki;        // bağlantıyı ters çeviririz.
        onceki = suankiNode;
        suankiNode = sonraki;
    }
    list->baslangic = onceki; // eski son node yeni başlangıç olur.
}

int addToEnd(linkedList* list, int degisken){
    return addToIndex(list, list->boyut, degisken);
}

// linked listin başlangıcından bir elemanı siler, sildiği elemanda bulunan sayıyı döndürür.
int popStart(linkedList* list){
    if (list->boyut == 0) {
        return 0;
    }
    node* tempNode = list->baslangic;
    int temp = tempNode->deger;
    list->baslangic = tempNode->siradaki;
    list->boyut--;
    free(tempNode);
    return temp;
}

int deleteFrom(linkedList* list, int index){
    if (index < 0 || index >= list->boyut)
        return 0;
    if(index == 0){
        return popStart(list);
    }
    // silinecek node'dan bir önceki node'a gideriz.
    node* suankiNode = list->baslangic;
    index--;
    while(index-- > 0){
        suankiNode = suankiNode->siradaki;
    }

    node* tempNode = suankiNode->siradaki;
    suankiNode->siradaki = tempNode->siradaki;
    int temp = tempNode->deger;
    free(tempNode);
    list->boyut--;
    return temp;
}

int popEnd(linkedList* list){
    return deleteFrom(list, list->boyut-1);
}


int editValue(linkedList* list, int index, int degisken){
    if (index < 0 || index >= list->boyut)
        return 0;
    node* suankiNode = list->baslangic;
    while(index--){
        suankiNode = suankiNode->siradaki;
    }
    suankiNode->deger = degisken;
    return 1;
}

// linked listteki tüm node'ları ve listenin kendisini serbest bırakır.
// bu fonksiyondan sonra list pointeri kullanılmamalıdır.
void freeLinkedList(linkedList* list){
    if (list == NULL)
        return;
    node* suankiNode = list->baslangic;
    while (suankiNode != NULL) {
        node* sonraki = suankiNode->siradaki; // free etmeden önce sonrakini saklarız.
        free(suankiNode);
        suankiNode = sonraki;
    }
    free(list);
}
