#include <stdio.h>
#include <stdlib.h>

typedef struct CELL{

    int value;
    struct CELL *next;

} CELL;

CELL *myInsert(CELL *p, int ba, int data);
void PrintList(CELL *p);

int main(){

    CELL *root;
    CELL *p;
    int data;
    int ba;

    printf("Input Number\n");
    scanf("%d", &data);

    root = (CELL *) malloc (sizeof (CELL));

    p = root;
    p -> value = data;
    p -> next = NULL;

    printf("Input Number\n");
    scanf("%d", &data);

    while (data > 0){

        p -> next = (CELL *) malloc (sizeof (CELL));
        p = p -> next;
        p -> value = data;

        printf("Input Number\n");
        scanf("%d", &data);
    }

    p -> next = NULL;

    printf("\n\n\nPrint List\n\n\n");
    PrintList(root); // リストの内容を表示

    printf("\n\n\nInput ba\n");
    scanf("%d", &ba);

    printf("Input data\n");
    scanf("%d", &data);

    printf("\n\n\nmy Insert");
    root = myInsert(root, ba, data);

    printf("\n\n\nPrint List\n\n\n");
    PrintList(root);

    return 0;
}

CELL *myInsert(CELL *p, int ba, int data){

    int i;
    CELL *q, *r;

    r = p;

    if (ba == 0){ // 0番目に挿入するとき

        p = (CELL *) malloc (sizeof (CELL));
        p -> value = data;
        p -> next = r;
        return p;
    
    }else{ // 1番目以降に挿入するとき
        
        for (i = 1 ; i < ba ; i++){
        
            p = p -> next;
        
        } // 挿入する場所までpを進める

        q = p -> next; // あいつを保存

        p -> next = (CELL *) malloc (sizeof (CELL));
        p -> next -> value = data;
        p -> next -> next = q;

        return r;
    }
}

void PrintList(CELL *p){

    for ( ; p != NULL ; p = p -> next){

        printf("%d\n", p -> value); // リストをスキャンする
    
    }
}
