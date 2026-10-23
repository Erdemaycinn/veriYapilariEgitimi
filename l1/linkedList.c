#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    void* siradaki; // next olarak isimlendirilir, bir node pointeridir.
    int deger; // payload, data, variable olarak isimlendirilebilir. linked listin taşıdığı değerdir.
}node;

typedef struct linkedList{
    node* baslangic; // head olarak isimlendirilir, bir node pointeridir.
    int boyut; // size olarak isimlendirilir. opsiyoneldir, ancak genelde performansa olan katkısı dolayısı ile eklenir.
    // node* tail // degişkeni eklenebilir. bu değişken bazı "use case" ler için gerekli olabilir.
}linkedList;

linkedList* newLinkedList(){
    linkedList* list = malloc(sizeof(linkedList));
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

int addToEnd(linkedList* list, int degisken){
    return addToIndex(list, list->boyut, degisken);
}

// linked listin başlangıcından bir elemanı siler, sildiği elemanda bulunan sayıyı döndürür.
int popStart(linkedList* list){
    if (list->boyut == 0) {
        return 0;
    }
    int temp = ((node*) (list->baslangic))->deger;
    node* tempNode = list->baslangic;
    list->baslangic = ((node*) (list->baslangic))->siradaki;
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
    node* suankiNode = list->baslangic;
    while(index--){
        suankiNode = suankiNode->siradaki;
    }

    node* tempNode = suankiNode->siradaki;
    suankiNode->siradaki = ((node*) (suankiNode->siradaki))->siradaki;
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
