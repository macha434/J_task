#include<stdio.h>

int main(void){
int c;
FILE *input;
input=fopen("document","r");


                 while((c=getc(input))!=EOF)
                 if (c!='\n')
		   printf("%c",c);
                 else
                 printf("%c",' ');
                 printf("%c",'\n');

fclose(input);
return 0;
}
