#include <stdio.h>

int main(void){

    char buffer[200], note[10][20];
    int i,j,k,now=1,next;
    char action;
    i=0;
    j=0;
    k=0;
    while(k<=199){
        if (now==1&& value(buffer[k])==1){
            action='a';
            next=1;
        }
        if (now==1&& value(buffer[k])==2){
            action='b';
            next=2;
        }
        if (now==1&& value(buffer[k])==3){
            action='c';
            next=3;
        }
        if (action=='a') {
            note[i][j]=buffer[k];
            k++;
            j++;
        }
        if (action=='b') {
                now=next;
        }
        return 0;
    }
}
