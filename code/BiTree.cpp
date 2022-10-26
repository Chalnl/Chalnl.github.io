#include<stdio.h>
#include<stdlib.h>

#define  OK 1
#define  ERROR 0
#define  OVERFLOW -2

typedef int Status;
typedef int TelemType;

typedef struct BiNode {
	TelemType data;
	struct BiNode* lchild, * rchild;
}BiTNode,*BiTree;

Status CreateBiTree(BiTree& T) {
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch; 
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status visit(TelemType e) {
	printf("%c ", e);
	return OK;
}


Status PreorderTraverse(BiTree T, Status(*visit)(TelemType e)) {
	if (T) {
		if (visit(T->data))
			if (PreorderTraverse(T->lchild, visit))
				if (PreorderTraverse(T->rchild, visit)) 
					return OK; 
		return ERROR;
	}
	else 
		return OK;
} 

Status InorderTraverse1(BiTree T, Status(*visit)(TelemType e)) {
	if (T) {
		if (InorderTraverse1(T->lchild, visit))
			if (visit(T->data))
				if (InorderTraverse1(T->rchild, visit)) 
					return OK;
		return ERROR;
	}
	else 
		return OK;
}

//中序非递归遍历
//Status InorderTraverse2(BiTree T, Status(*visit)(TelemType e)) {
//
//}

Status PostorderTraverse(BiTree T, Status(*visit)(TelemType e)) {
	if (T) {
		if (PostorderTraverse(T->lchild, visit))
			if (PostorderTraverse(T->rchild, visit))
				if (visit(T->data))return OK;
		return ERROR;
	}
	else 
		return OK;
}


int main() {
	BiTree T;
	CreateBiTree(T);

	PreorderTraverse(T, *visit);
	printf("\n");

	InorderTraverse1(T, *visit);
	printf("\n");

	PostorderTraverse(T, *visit);
	return 0;
}