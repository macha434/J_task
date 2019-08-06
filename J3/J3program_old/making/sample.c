#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct CELL{
    char *num;
    char *nam;
    int age;
}CELL;

int main(void){

    char number[255];
    char name[255];
    int age;

    CELL *member;

    int len1;
    int len2;

    printf("What's your number ? :");
    scanf("%s", number);

    len1 = strlen(number);

    member -> num = (char *) malloc (sizeof (len1));

    printf("What's your name ? :");
    scanf("%s", name);

    len2 = strlen(number);

    member -> nam = (char *) malloc (sizeof (len2));

    printf("How old are you ? :");
    scanf("%d", &age);

    member -> age = age;

    printf("Ok\n");

    free(member -> num);
    free(member -> nam);

    return 0;
}
