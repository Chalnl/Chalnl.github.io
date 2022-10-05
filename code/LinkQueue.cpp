#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e) {
	QueuePtr p= (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& Q) {
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p = Q.front->next; 
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

Status DestroyQueue(LinkQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status PrintQueue(LinkQueue& Q){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (Q.front == Q.rear)
		return OVERFLOW;
	//printf("%d ", Q.front);
	//printf("%d ", Q.rear);
	p = Q.front->next;
	printf("The LinkQueue is:\n");
	while (p != Q.rear->next) {
		printf("%d ", p->data);
		p = p->next;
	}
	return OK;
}

int main() {
	int n,e;
	char chr;
	LinkQueue Q;
	InitQueue(Q);
	printf("Please input the length of the LinkQueue:\n");
	scanf("%d", &n);

	printf("Please input the element of the LinkQueue:\n");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &e);
		EnQueue(Q, e);
	}
	PrintQueue(Q);

	printf("\nWhether delete the front of the QNode:(y/n)\n");
	scanf(" %c", &chr);
	if (chr == 'y' || chr == 'Y') {
		//printf("%d",DeQueue(Q));
		DeQueue(Q);
	}
	PrintQueue(Q);
	DestroyQueue(Q);
	return 0;
}