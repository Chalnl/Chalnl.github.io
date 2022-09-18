#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	int elem;
	struct Link* next;
}link;

link* initLink(int n) {
	link* p = (link*)malloc(sizeof(link));
	link* temp = p;
	for (int i = 0; i < n; ++i) {
		link* a = (link*)malloc(sizeof(link));
		a->elem = i + 1;
		a->next = p->next;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

//void printlink(link* p,int n) {
//	link* temp = p;
//	for (int i = 0; i < n; ++i) {
//		temp = temp->next;
//		printf("%3d", temp->elem);
//	}
//	printf("\n");
//}

int main() {
	int n, i;
	scanf("%d %d", &n, &i);
	link *p= initLink(n);

	while (n!=1) {
		for (int j = 1; j < i; ++j) {
			p = p->next;
		}
		link* del = p->next;
		p->next = p->next->next;
		n--;
		free(del);
//		printlink(p, n);
	}
	printf("%d", p->elem);
	return 0;
}