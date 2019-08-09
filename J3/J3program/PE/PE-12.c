#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void set_hash(char words[],int hasher[])
{
  int hash_val=0;
  for(int i=0;i<strlen(words);i++) hash_val+=abs((int)words[i]-'a')+i;
  hasher[hash_val]++;
}

int hash(char words[])
{
  int hash_val=0;
  for(int i=0;i<strlen(words);i++) hash_val+=abs((int)words[i]-'a')+i;
  return hash_val;
}

int main()
{
  int i=0,j=0;
  int c=0;
  int val;
  char word[1000][1000];
  char str[1000];
  static int hasher[10000];
  bool flag=true;

  printf("Input Strings : ");
  scanf("%[^\n]",str);

  for(i=0;i<strlen(str);i++){
    if(str[i]==' '||str[i]==','){i++;j++;c=0;}
    word[j][c]=str[i];
    c++;
  }
  c=j;

  for(i=0;i<=c;i++){
    set_hash(word[i],hasher);
    printf("%d\n",hash(word[i]));
  }

  for(i=0;i<=c;i++){
    val=hash(word[i]);
    if(hasher[val]>0){
      printf("%s \n",word[i]);
      hasher[val]=0;
    }
  }

  return 0;
}
