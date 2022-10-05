#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

typedef  int Status;
typedef  int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

void CreateList_L(LinkList& L, int n) {      
	L = (LinkList)malloc(sizeof(LNode));    
	L->next = NULL;                    
	LinkList temp = L;                     
	for (int i = 0; i < n; ++i) {
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);              
		temp->next = p;                    
		temp = p;                         
	}
	temp->next = NULL;

}

//void CreateList_L(LinkList& L, int n) {    
//	L = (LinkList)malloc(sizeof(LNode));     
//	L->next = NULL;
//	for (int i = 0; i < n; ++i) {
//		LinkList p = (LinkList)malloc(sizeof(LNode));
//		scanf("%d", &p->data);             
//		p->next = L->next;               
//		L->next = p;                      
//	}
//}

Status ListInsert_L(LinkList& L, int i, ElemType e) {  
	LinkList temp = L;
	int j ;
	for (j=1; j < i; ++j) {
		if (temp == NULL)
			return ERROR;
		temp = temp->next;
	}
	if (!temp || j > i)
		return ERROR;
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	p->next = temp->next;
	temp->next = p;
	return OK;
}

Status ListDelete_L(LinkList& L, int i,ElemType e) {  
	LinkList temp = L;
	int j;
	for (j = 1; j < i; ++j) 
		temp = temp->next;
	if (!(temp->next) || j > i)
		return ERROR;
	LinkList del = temp->next;
	temp->next = del->next;
	e = temp->data;
	free(del);
	return OK;
}

void printList(LinkList p) {
	LinkList temp = p;                    
	printf("The LinkList is:\n");
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
}


int main() {
	int n, i, e, j, h;
	LinkList p;

	printf("Please input the length of the linklist:\n");
	scanf("%d", &n);

	printf("Please input the element of the linklist:\n");
	CreateList_L(p, n);
	printList(p);

	printf("Please input the position to insert:\n");
	scanf("%d", &i);
	printf("Please input the elements:\n");
	scanf("%d", &e);
	ListInsert_L(p, i, e);
	printList(p);

	printf("\nPlease input the position to delete:\n");
	scanf("%d", &j);
	printf("Please input the elements:\n");
	scanf("%d", &h);
	ListDelete_L(p, j, h);
	printList(p);

	return 0;
}