#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

typedef  int Status;
typedef  int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLLinkList;

void CreateList_DuL(DuLLinkList& L, int n) {
	L = (DuLLinkList)malloc(sizeof(DuLNode));
	L->next = NULL;                    
	DuLLinkList temp = L; 
	for (int i = 0; i < n; ++i) {
		DuLLinkList p = (DuLLinkList)malloc(sizeof(DuLNode));
		scanf("%d", &p->data);
		temp->next = p; 
		temp->next->prior = temp;
		temp = p; 
	}
	temp->next = NULL;
}

Status ListInsert_DuL(DuLLinkList& L, int i, ElemType e) {
	DuLLinkList temp = L;
	int j ;
	for (j=1; j < i; ++j) {
		if (temp == NULL)
			return ERROR;
		temp = temp->next;
	}
	if (!temp || j > i)
		return ERROR;
	DuLLinkList p = (DuLLinkList)malloc(sizeof(DuLNode));
	p->data = e;
	p->prior = temp;
	p->next = temp->next;
	temp->next->prior = p;
	temp->next = p;
	return OK;
}

Status ListDelete_DuL(DuLLinkList& L, int i,ElemType e) {
	DuLLinkList temp = L;
	int j;
	for (j = 1; j < i; ++j) 
		temp = temp->next;
	if (!(temp->next) || j > i)
		return ERROR;
	DuLLinkList del = temp->next;
	temp->next->next->prior = temp;
	temp->next = temp->next->next;
	e = del->data;
	free(del);
	return OK;
}

void printList(DuLLinkList p) {
	DuLLinkList temp = p;
	printf("The DuLLinkList is:\n");
	while (temp->next) {
		temp = temp->next;
		printf("%d ", temp->data);
	}
	printf("\n");
}


int main() {
	int n, i, e, j, h;
	DuLLinkList p;

	printf("Please input the length of the DuLLinkList:\n");
	scanf("%d", &n);

	printf("Please input the element of the DuLLinkList:\n");
	CreateList_DuL(p, n);
	printList(p);

	printf("Please input the position to insert:\n");
	scanf("%d", &i);
	printf("Please input the elements:\n");
	scanf("%d", &e);
	ListInsert_DuL(p, i, e);
	printList(p);

	printf("\nPlease input the position to delete:\n");
	scanf("%d", &j);
	printf("Please input the elements:\n");
	scanf("%d", &h);
	ListDelete_DuL(p, j, h);
	printList(p);

	return 0;
}