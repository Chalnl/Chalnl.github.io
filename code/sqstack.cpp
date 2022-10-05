#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int SElemType;

typedef struct{
	SElemType* top;
	SElemType* base;
	int stacksize;
}SqStack;

Status Initstack(SqStack& s) {
	s.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); 
	if (!s.base) 
		exit(OVERFLOW);
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE; 
	return OK;
} 

//Status CreateSqStack(SqStack& s,int &n) {
//	int e;
//	for (int i = 0; i < n; ++i) {
//		scanf("%d", &e);
//		*s.top++ = e;
//	}
//	return OK;
//}

Status Push(SqStack& s, SElemType e) {
	if (s.top - s.base >= s.stacksize){
		s.base = (SElemType*)realloc(s.base,(s.stacksize + STACKINCREMENT) * sizeof(SElemType) ) ;
		if (!s.base) 
			exit(OVERFLOW); 
		s.top = s.base + s.stacksize; 
		s.stacksize += STACKINCREMENT; 
	}
	* s.top++ = e; 
	return OK;
} 

Status Pop(SqStack& s) {
	if (s.top == s.base) 
		return ERROR; 
	s.top--;
	//printf("%d ", * --s.top);
	return OK;
}

Status StackEmpty(SqStack& S) {
	if (S.base == S.top) {
		printf("The SqStack is Empty\n");
		return OK;
	}
	printf("The SqStack is not Empty\n");
	return OK;
}

void StackTraverse(SqStack& S) {
	SElemType* p = S.top;
	printf("The SqStack is:\n");
	while (p > S.base) {
		printf("%d ", *--p);
	}
	printf("\n");
}

Status conversion() {
	SqStack Sq;
	Initstack(Sq);
	int N;
	scanf("%d", &N);
	while (N) {
		Push(Sq,N % 8);
		N = N / 8;
	}
	printf("The octal number is:\n");
	while (Sq.top > Sq.base) {
		printf("%d", *--Sq.top);
	}
	return OK;
} 


int main() {
	int n, e;
	char chr;
	SqStack S;
	Initstack(S);

	printf("Please input the length of the SqStack:\n");
	scanf("%d", &n);

	printf("Please input the element of the SqStack:\n");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &e);
		Push(S, e);
	}

	printf("Whether delete the top of the stack:(y/n)\n");
	scanf(" %c", &chr);
	if (chr == 'y' || chr == 'Y')
		Pop(S);

	StackEmpty(S);
	//CreateSqStack(S, n);
	//printf("\n%d", S.top);
	//printf("\n%d", S.base);
	//printf("\n%d", S.top - S.base);
	StackTraverse(S);

	printf("Please enter a decimal number:\n");
	conversion();

	return 0;
}