#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct CELL {
	char ch;
	int mask;
	struct CELL *next;
} CELL;

void print_list(CELL *root);

int main(void)
{
	CELL root;
	CELL *p;
	int i;
    int c;

	char word[50];

    printf ("Input word : ");
    scanf ("%s", word);

    c = strlen (word);

	srand((unsigned)time(NULL));

	root.next = NULL;
	p = &root;
	
	for  ( i = 0; i < c; i++ ) {
		p->next = (CELL *)malloc(sizeof(CELL));
		p = p->next;
		p->ch = word[i];
		p->mask = rand()%2;
	}
	p->next = NULL;

	print_list(root.next);

	return 0;
}
	
void print_list(CELL *root)
{
	CELL *p;
	
	for (p = root; p != NULL; p = p->next) {
        if (p -> mask == 1){
            printf("-");
        }else{
            printf("%c", p->ch);
        }
	}
	printf("\n");
}
	
