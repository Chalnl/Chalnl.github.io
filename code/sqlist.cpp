#include <stdlib.h>
#include <stdio.h>

#define  OK 1
#define  ERROR 0
#define OVERFLOW -2

typedef  int status;  
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct{
    ElemType* elem;
    int length;
    int listsize;
}SqList;

status InitList(SqList& L){
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

status ListInsert_Sq(SqList& L, int i, ElemType e){
    ElemType* newbase, * p, * q;
    if (i<1 || i>L.length + 1) 
        return ERROR;
    if (L.length >= L.listsize){
        newbase = (ElemType*)realloc(L.elem, 
            (L.listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) 
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize = L.listsize + LISTINCREMENT;
    }
    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; --p) 
        *(p + 1) = *p;
    *q = e;
    L.length++;
    return OK;
}

status ListDelete_Sq(SqList& L, int i, ElemType& e){
    ElemType* p, * q;
    if ((i < 1) || i > L.length)
        return ERROR;
    p = &L.elem[i - 1];
    e = *p;
    q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return OK;
}

status printList(SqList L){
    int i;
    printf("The SqList is:\n");
    for (i = 0; i < L.length; ++i)
        printf("  %d  ", L.elem[i]);
    return OK;
}

int main(){
    SqList L;
    int n, i, elem, e, a, j;
    InitList(L);
    printf("Please input the length of the sqlist:\n");
    scanf("%d", &n);
    printf("Please input the element of the sqlist:\n");
    for (i = 1; i <= n; ++i){
        scanf("%d", &elem);
        ListInsert_Sq(L, i, elem);
    }
    printList(L);

    printf("\nPlease input the position to insert:\n");
    scanf("%d", &i);
    printf("Please input the elements:\n");
    scanf("%d", &e);
    ListInsert_Sq(L, i, e);
    printList(L);

    printf("\nPlease input the length to delete the size of sqlist:\n");
    scanf("%d", &a);
    printf("Please input the place to deldte size:\n");
    for (j = 1; j <= a; ++j){
        scanf("%d", &e);
        ListDelete_Sq(L, 1, e);
    }
    printList(L);
    return 0;
}
