#include <stdio.h>


char *insert_strings(char str[]);
/* int check_str(char clone_str[5][10], char *strings, int num); */
/* void print_str(char clone_str[5][10]); */

int main(){

    printf("a");
    char str[] = "kisarazu kosen kisarazu chiba japan";
    char *clone_str;

    printf("a");
    clone_str = insert_strings(str);

    printf("a");
    /* print_str(clone_str); */

    return 0;
}

char *insert_strings(char str[]){

    int i, j, k;
    char clone_str[5][10];

    k = 0;

    for (i = 0; str[k] != '\0'; i++){

        for (j = 0; str[k] != ' '; k++, j++){

            clone_str[i][j] = str[k];
        }

        /* clone_str[i][j] = '\0'; */

    /*     /1* i = check_str(clone_str, &clone_str[i][0], i); *1/ */

        k++;
    }

    return &clone_str[0][0];
}

/* int check_str(char clone_str[5][10], char *strings, int num){ */

/*     int i, j; */
/*     int n; */

/*     n = num; */

/*     for (i = 0; i < n; i++){ */

/*         for (j = 0; clone_str[i][j] ==  strings[j]; j++){ */

/*             if (clone_str[i][j] == '\0') return n--; */
/*         } */
/*     } */

/*     return num; */
/* } */

/* void print_str(char clone_str[5][10]){ */

/*     int size; */

/*     size = sizeof(*clone_str) / sizeof(**clone_str); */

/*     for (int i = 0; i < size; i++){ */

/*         printf("%s\n", clone_str[i]); */
/*     } */
/* } */
