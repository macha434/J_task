#include <stdio.h>

void insert_strings(char str[], char clone_str[5][10]);
int check_str(char clone_str[5][10], char *strings, int num);
void print_str(char clone_str[5][10]);

int main(){

    char str[] = "kisarazu kosen kisarazu chiba japan";
    char clone_str[5][10];

    insert_strings(str, clone_str);

    print_str(clone_str);

    return 0;
}

void insert_strings(char str[], char clone_str[5][10]){

    int i, j, k;

    k = 0;

    for (i = 0; str[k] != '\0'; i++){

        for (j = 0; str[k] != ' '; k++, j++){

            clone_str[i][j] = str[k];
        }

        clone_str[i][j] = '\0';

        i = check_str(clone_str, &clone_str[i][0], i);

        k++;
    }
}

int check_str(char clone_str[5][10], char *strings, int num){

    int i, j;
    int n;

    n = num;

    for (i = 0; i < num; i++){

        for (j = 0; clone_str[i][j] ==  strings[j]; j++){

            if (clone_str[i][j] == '\0') return num--;
        }
    }

    return num;
}

void print_str(char clone_str[5][10]){

    int size;

    size = sizeof(*clone_str) / sizeof(**clone_str);

    for (int i = 0; i < size; i++){

        printf("%s\n", clone_str[i]);
    }
}
