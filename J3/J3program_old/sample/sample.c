#include<stdio.h>
#include<stdlib.h>
#include "../include/typedef.h"

CELL *makeList(void);
//CELL *getPointer(CELL *);
void printList(CELL *, int);
void myFreeOK(CELL *);

int main(void)
{
    CELL *root = NULL;
	//CELL *addressList = NULL;

	printf("In main\n\n");
	
	printf("%p, %ld\n", root, (unsigned long)root);
	
	printf("\n");
	root = makeList();
	printf("\n");
	printList(root, 0);
	
	//addressList = getPointer(root);
	//printList(addressList, 1);

	myFreeOK(root);

	/*
	printf("\n");
	root = makeList();
    */

	printf("\n");

	printList(root, 0);
	
	return 0;
}

CELL *makeList(void)
{
	CELL root;
  	CELL *p = &root;
	int data;

	printf("In makeList\n\n");

  	printf("Input data: ");
	scanf("%d", &data);
	
	while (data > 0) {
    		if ( (p->next = (CELL *)malloc(sizeof(CELL))) == NULL) {
      			exit(1);
		}
    
		p = p->next;
		//for check use
		printf("p = %p, p->next = %p\n", p, p->next);

		p->value = data;
    
		printf("Input data: ");
		scanf("%d", &data);
	}
	p->next = NULL;

	return root.next;
}

/*
CELL *getPointer(CELL *p)
{
	CELL root;
	CELL *q = &root;

	for( ; p != NULL; p = p->next) {
    		if ( (q->next = (CELL *)malloc(sizeof(CELL))) == NULL) {
			exit(1);
		}
		q = q->next;
		q->pvalue = p;
	}
	q->next = NULL;

	return root.next;
}
*/

void printList(CELL *p, int mySwitch)
{
	printf("In printList\n\n");

	for ( ; p != NULL; p = p->next ) {
		if (mySwitch) {
			printf("%p\n", p->pvalue);
		} else {
			printf("%d\n", p->value);
		}
	}
}

void myFreeOK(CELL *p)
{
	CELL *q;

	printf("In myFreeOK\n\n");

	for (q = p; p != NULL; p = q) {
		q = p->next;
		printf("q = %p\n", q);

		//for check use
		printf("p = %p, p->next = %p\n", p, p->next);

		free(p);
	}
}
