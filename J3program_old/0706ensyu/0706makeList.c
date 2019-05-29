#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	struct CELL *prev;
	int value;
	struct CELL *next;
} CELL;

void printList(CELL *root);
void insertValueToList(CELL *p);
void deleteValueToList(CELL *p);
void clearList(CELL *root);

int main(void)
{
	int menuNum;
	CELL root;

	root.prev = &root;
	root.next = &root;
	
	for( ; ; ) {
		printf("\nMENU:  select number\n");
		printf("1:Print, 2:Insert, 3:Delete, 4:Initialize, 5:Exit\n");
		scanf("%d", &menuNum);
		if ( menuNum == 1 ) {
			printList( &root );
		} else if ( menuNum == 2 ) {
			insertValueToList( &root );
		} else if ( menuNum == 3 ) {
			deleteValueToList( &root );
		} else if ( menuNum == 4 ) {
			clearList( &root );
		} else if ( menuNum == 5 ) {
			break;
		}
	}

	clearList( &root );

	printf("\nBye!\n\n");

	return 0;
}

void printList(CELL *root)
{
	CELL *p;

	for (p = root->next ; p != root ; p = p->next ) {
		printf( "%d ", p->value );
	}
	printf("\n");

	for (p = root->prev ; p != root; p = p->prev ) {
		printf( "%d ", p->value );
	}
	printf("\n");

}

void insertValueToList(CELL *p)
{
	int data;
	int basyo;
	int i;
	CELL *q;
	
	printf("Input data: ");
	scanf("%d", &data);
	printf("Input basyo: ");
	scanf("%d", &basyo);

	for ( i = 0; i < basyo; i++) {
		p = p->next;
	}
	
	q = p->next;
	p->next = (CELL *)malloc(sizeof(CELL));
	p->next->value = data;
	p->next->prev = p; 
	p->next->next = q;
	q->prev = p->next;
}

//You can write program here!
void deleteValueToList(CELL *p)
{
	
}

//You can write program here!
void clearList(CELL *root)
{
    CELL *q;

    for (q = root -> prev ; q -> prev -> value != root -> value ; q = q -> prev){
        
    }

}
