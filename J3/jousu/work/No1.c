#include <stdio.h>

void buffer_to_array2D();

int main(){

    char buffer[200];
    char note[10][20];

    printf("Input Buffer : ");
    scanf("%[^\n]", buffer);

    buffer_to_array2D(buffer, note);

    return 0;
}

void buffer_to_array2D(char buffer[], char note[][20]){

    int j;
    int k = 0;

    for(int i = 0; buffer[i] != '\0'; i++, k++){
        for(j = 0; buffer[i] != '\0'; i++, j++){
            note[k][j] = buffer[i];
        }
        note[k][j] = '\0';
        i++;
    }

    for(int i = 0; i < k; i++){
        printf("%s\n", note[i]);
    }

    return;
}
