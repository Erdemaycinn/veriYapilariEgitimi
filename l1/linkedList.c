#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    void* siradaki; // next olarak isimlendirilir, bir node pointeridir.
    int deger; // payload, data, variable olarak isimlendirilebilir. linked listin taşıdığı değerdir.
}node;

typedef struct linkedList{
    node* baslangic; // head olarak isimlendirilir, bir node pointeridir.
    int boyut; // size olarak isimlendirilir. opsiyoneldir, ancak genelde performansa olan katkısı dolayısı ile eklenir.
    node* son; // tail olarak isimlendirilir, listenin son node'unu gösterir. sona ekleme işlemini O(1) yapar.
}linkedList;

int addToEnd(linkedList* list, int degisken); // addToIndex içinde kullanıldığı için önceden bildirilir.

linkedList* newLinkedList(){
    linkedList* list = malloc(sizeof(linkedList));
    if (list == NULL)
        return NULL;
    list->baslangic = NULL;
    list->son = NULL;
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
    // liste boşsa eklenen eleman aynı zamanda son elemandır.
    if (list->son == NULL)
        list->son = suankiNode;
    list->boyut++;
    return 1;
}


int addToIndex(linkedList* list, int index, int degisken){

    if (index < 0 || index > list->boyut)
        return 0;
    if(index == 0)
        return addToStart(list, degisken);
    // sona ekleme son pointeri sayesinde listeyi gezmeden yapılır.
    if(index == list->boyut)
        return addToEnd(list, degisken);

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
void reverseLinkedList(linkedList* list){
    node* onceki = NULL;
    node* suankiNode = list->baslangic;

    // eski başlangıç ters çevrilmiş listenin son elemanı olur.
    list->son = list->baslangic;

    while (suankiNode != NULL) {
        node* sonraki = suankiNode->siradaki;
        suankiNode->siradaki = onceki;
        onceki = suankiNode;
        suankiNode = sonraki;
    }
    list->baslangic = onceki;
}

// linked listin sonuna eleman ekler. son pointeri sayesinde O(1) çalışır.
int addToEnd(linkedList* list, int degisken){
    if (list->boyut == 0)
        return addToStart(list, degisken);

    node* yeniNode = malloc(sizeof(node));
    if (yeniNode == NULL)
        return 0;
    yeniNode->deger = degisken;
    yeniNode->siradaki = NULL;
    list->son->siradaki = yeniNode;
    list->son = yeniNode;
    list->boyut++;
    return 1;
}

// linked listin başlangıcından bir elemanı siler, sildiği elemanda bulunan sayıyı döndürür.
int popStart(linkedList* list){
    if (list->boyut == 0) {
        return 0;
    }
    int temp = ((node*) (list->baslangic))->deger;
    node* tempNode = list->baslangic;
    list->baslangic = ((node*) (list->baslangic))->siradaki;
    // liste boşaldıysa son pointeri de NULL olmalıdır.
    if (list->baslangic == NULL)
        list->son = NULL;
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
    // silinecek node'dan bir önceki node'a kadar ilerleriz.
    node* suankiNode = list->baslangic;
    while(--index){
        suankiNode = suankiNode->siradaki;
    }

    node* tempNode = suankiNode->siradaki;
    suankiNode->siradaki = tempNode->siradaki;
    // son eleman silindiyse önceki node yeni son eleman olur.
    if (tempNode == list->son)
        list->son = suankiNode;
    int temp = tempNode->deger;
    free(tempNode);
    list->boyut--;
    return temp;
}

int popEnd(linkedList* list){
    return deleteFrom(list, list->boyut-1);
}


int editValue(linkedList* list, int index, int degisken){
    if (index < 0)
        return 0;
    if (list->boyut-1 <= index)
        return 0;
    node* suankiNode = list->baslangic;
    while(index--){
        suankiNode = suankiNode->siradaki;
    }
    suankiNode->deger = degisken;
    return 1;
}


int main(){
    linkedList* list = newLinkedList();
    addToStart(list, 8);
    addToEnd(list, 6);
    addToIndex(list, 1, 16);
    printf("sayilar %d %d %d\n",getElement(list,0),getElement(list,1),getElement(list,2));
}
