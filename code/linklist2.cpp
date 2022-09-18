#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
	int elem;
	struct Link* next;
}link;

link* initLink() {
	link* p = (link*)malloc(sizeof(link));
	link* temp = p;
	for (int i = 1; i <= 10; ++i) {
		link* a = (link*)malloc(sizeof(link));
		a->elem = 0;
		a->next = p->next;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}

void printlink(link* p,int n) {
	link* temp = p;
	for (int i = 0; i < n; ++i) {
		temp = temp->next;
		printf("%3d", temp->elem);
	}
	printf("\n");
}

int main() {
	link* p = initLink();
	int n = 1000, i = 1;
	//printlink(p,10);
	link* a = p;

	while (n != 1) {
		for (int j = 1; j <= i;++j) {
			a = a->next;
		}
		a->elem = 1;
		++i;
		n--;
	//	printlink(p, 10);
	}
	//printlink(p, 10);
	p = p->next;
	for (int i = 1; i <= 10; ++i) {
		//printf("%d ", p -> elem);
		if (p->elem == 0)
			printf("兔子可能藏在%d号洞\n", i);
		p = p->next;
	}
	return 0;
}