#include <stdio.h>

int main(){
    int i, j, k;
    bool flag = 0;
    char str[] = "Kisarazu Kosen Kisarazu Chiba Japan";
    char clone[255][255] = "";

    i = 0;
    k = 0;

    make_clone(str, clone);

    for (j = 0; str[i] != '\0'; j++){

        clone[k][k + 1] = '\0';

        flag = check_str(clone, clone[j][0]);

        if (flag){

            add_str(str, clone);

        }else{

            k++;

        }
    }

    printf("%s\n", clone);
}

void make_clone(char str[], clone[][]){

    int i, j;

    for (j = 0; str[i] != '\0'; j++){

        if (str[j] == ' '){

            clone[k][j + 1] = '\n'
            k++;
        }

        clone[k][j] = str[i];

    }
}

bool check_str(char **str, char *word){

    bool frag = 0;

    if (**str == '\0' || *word == '\0'){

        j++;

    }
    check_str(str[j][i], word[i]);
}
