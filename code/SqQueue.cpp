#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

#define  MAXQSIZE 100

typedef int Status;
typedef int QElemType;

typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue& Q) {
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue& Q) {
	if (Q.front == Q.rear)
		return ERROR;
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status PrintQueue(SqQueue Q) {
	if (Q.front == Q.rear)
		return ERROR;
	int n = QueueLength(Q);
	printf("The SqQueue is:\n");
	for (int i = 0; i < n; ++i)
		printf("%d ",Q.base[Q.front+i]);
	//printf("\n%d ", Q.base[Q.front]);
	//printf("%d ", Q.base[Q.rear]);

	//printf("\n%d ", Q.front);
	//printf("%d ", Q.rear);
	return OK;
}

int main() {
	int n, e;
	char chr;
	SqQueue Q;
	InitQueue(Q);
	printf("Please input the length of the SqQueue:\n");
	scanf("%d", &n);

	printf("Please input the element of the SqQueue:\n");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &e);
		EnQueue(Q, e);
	}
	PrintQueue(Q);

	printf("\nWhether delete the front of the QNode:(y/n)\n");
	scanf(" %c", &chr);
	if (chr == 'y' || chr == 'Y') 
		DeQueue(Q);
	PrintQueue(Q);
	return 0;
}