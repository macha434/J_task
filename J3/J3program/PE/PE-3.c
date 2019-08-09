#include <stdio.h>

int main(){
    int i, j, k;
    int flag = 0;
    char str[] = "Kisarazu Kosen";
    char ans[15] = "";

    i = 0;
    k = 0;

    for (j = 0; str[i] != '\0'; j++){

        ans[k + 1] = '\0';

        if (ans[j] == '\0'){

            if (flag == 0){

                ans[k] = str[i];

                k++;
            } else {

                flag--;
            }

            i++;

            j = 0;
        }

        if (str[i] == ans[j]){

            flag = 1;
        }
    }

    printf("%s\n", ans);
}
