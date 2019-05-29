#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	struct CELL *prev;
	int value;
	struct CELL *next;
} CELL;

void printList(CELL *root);
void mySort(CELL *root);

int main(void)
{
	CELL root;
	CELL *p = &root;
	int a[5] = {3, 5, 2, 4, 1};
	int x;

	for ( x = 0; x < 5; x++ ) {
		p->next = (CELL *)malloc(sizeof(CELL));
		p->next->prev = p;
		p = p->next;
		p->value = a[x];
	}
	p->next = &root;
	root.prev = p;

	printList(&root);

	mySort(&root);
	
	printList(&root);

	return 0;
}

void printList(CELL *root)
{
	CELL *p;

	for (p = root->next; p != root; p = p->next ) {
		printf("%d ", p->value);
	}
	printf("\n\n");

	for (p = root->prev; p != root; p = p->prev ) {
		printf("%d ", p->value);
	}
	printf("\n\n");
}

void mySort(CELL *root)
{
	CELL *i, *j;
	int x;

	for ( i = root->next; i->next != root; i = i->next ) {
		for (j = i->next; j != root; j = j->next ) {
			if (i->value > j->value) {
				x = i->value;
				i->value = j->value;
				j->value = x;
			}
		}
	}
}