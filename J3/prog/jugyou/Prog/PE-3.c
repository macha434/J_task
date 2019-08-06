#include <stdio.h>
#include <string.h>
int main()
{
  char str[500];
  int chars[128];
  scanf("%[^\n]",str);

  for(int i=0;i<strlen(str);i++){
    chars[str[i]]++;
  }

  for(int i=0;i<strlen(str);i++){
    if(chars[str[i]]) printf("%c",str[i]);
    chars[str[i]]=0;
  }
  printf("\n");
}
/*AA
char[A]=0;
*/
