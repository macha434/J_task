#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{
    char name[20];
    int value;
    int period;
    struct CELL *next;
    struct CELL *prev;
}CELL;

CELL *add_prod();
void discount();
void deleat();
void prod_sort();
void cell_free();
void print_list();

int main(){
    int date;
    int num;
    CELL *root;
    root = (struct CELL *) malloc (sizeof (CELL));
    CELL *tail = root;

    printf("Input date (Ex 2020/02/06 → 20200206) : ");
    scanf("%d", &date);

    while(1){
        printf("Select Mode : 1:product add, 2:product discout, 3:product deleat, 4:sort, 5:exit : ");
        scanf("%d", &num);

        switch(num){
            case 1:
                tail = add_prod(tail);
                break;

            case 2:
                discount(root, date);
                break;

            case 3:
                deleat(root, date, tail);
                break;

            case 4:
                prod_sort(root, tail);
                break;

            case 5:
                cell_free(root, tail);
                break;
        }
    }
}

CELL *add_prod(CELL *root){
    int i;
    char name[20];
    int value;
    int period;
    root -> next = (CELL *) malloc (sizeof (CELL)) ;
    CELL *product = root -> next;

    for(;; product = product -> next){
        printf("Input product name : ");
        scanf("%s", product -> name);

        printf("Input product value : ");
        scanf("%d", &product -> value);

        printf("Input product period (Ex 2020/02/06 → 20200206) : ");
        scanf("%d", &product -> period);

        print_list(root);

        printf("Continue ? 1:yes 2:no : ");
        scanf("%d", &i);
        if(i != 1) break;

        product -> next = (CELL *) malloc (sizeof (CELL));
        product -> next -> prev = product;
    }

    product -> next = NULL;

    return product;

}

void discount(CELL *root, int date){
    CELL *product = root -> next;

    for(; product != NULL ; product = product -> next){
        if(product -> period == date) product -> value = product -> value * 0.7;
    }

    print_list(root);

}

void deleat(CELL *root, int date){
    CELL *product = root -> next;
    CELL *swap = NULL;

    for (; product != NULL; product = product -> next){
        if (swap != product) free(swap);

        if(product -> period < date){
            product -> prev -> next = product -> next;
            product -> next -> prev = product -> prev;

            swap = product;
        }
    }

    print_list(root);
}

void prod_sort(CELL *root){
    CELL *product = root -> next;
    CELL * prod = root -> next;
    CELL *swap;

    for(; prod != NULL ; prod = prod -> next){
        for(product = prod ; product != NULL ; product = product -> next){
            if(product -> period > product -> next -> period){
                swap = product -> next -> next;
                product -> next -> prev = product -> prev;
                product -> next -> next = product;
                product -> prev = product -> next;
                product -> next = swap;
            }
        }
    }
}

void print_list(CELL *root){
    int i;

    for(root = root -> next ; root != NULL ; root = root -> next, i++){
        printf("%d : ", i);
        printf("name %s, ", root -> name);
        printf("value %d, ", root -> value);
        printf("period %d\n", root -> period);
    }
}

void cell_free(CELL *root, CELL *tail){
    while(root != NULL){
        tail = tail -> prev;
        free(tail -> next);
    }

    free(root);

    exit(0);
}
