#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define HASHSIZE 500		//SIZE
#define MAX_KW_LEN 256		//charactor MAX
#define NUM_KW 500		//word MAX
#define SIZE 500

struct HASH{
  char keyword[MAX_KW_LEN];
  struct HASH *next;
};

typedef struct HASH Hash;

Hash *hashtable[HASHSIZE];

int Get_Hash(char*key);
int Add_HTable(char *kw);
int FindKeyWord(char*key);
void ListKeyWord(void);
void FreeKeyWord(void);
int main(void);

int Get_Hash(char*key)
{
  int hashval=0;

  while(*key!='\0')
    hashval+=*key++;

  return(hashval%HASHSIZE);	//SaveforSizeOver
}

int Add_HTable(char *kw)
{
  int i;
  Hash *p,*q;
  int hashval;
  static int Hit_num;
  for(i=0;i<NUM_KW;i++){
    if((FindKeyWord(kw))==false){
      if((p=(Hash*)malloc(sizeof(Hash)))==NULL){
	fprintf(stderr,"Memory Err0r \n");
	exit(2);
      }
      strcpy((*p).keyword,kw);
      hashval=Get_Hash(kw);

      if(hashtable[hashval]==NULL){
	hashtable[hashval]=p;
	p->next=NULL;
      }else{
	Hit_num++;
	q=hashtable[hashval];
	while(q->next!=NULL)
	  q=q->next;
	q->next=p;
	p->next=NULL;
      }
    }
  }
  return Hit_num;
}

int FindKeyWord(char*key)
{
  Hash *p;

  for(p=hashtable[Get_Hash(key)];p!=NULL;p=p->next)
    if(!strcmp(key,(*p).keyword))
      return(true);

  return(false);
}

void FreeKeyWord(void)
{
  int i;
  Hash *p,*q;

  for(i=0;i<HASHSIZE;i++)
    for(p=hashtable[i];p!=NULL;){
      q=p->next;
      free(p);
      p=q;
    }
}


int main(void)
{
  char str[SIZE];
  char word[NUM_KW][MAX_KW_LEN];
  static int i,j,c;
  int num;
  ADD_WORD:
  printf("Please Enter string>");
  scanf("%[^\n]",str);
  char ct=getchar();
  for(i=0;i<strlen(str);i++){
    if(str[i]==' '||str[i]==','){i++;j++;c=0;}
    word[j][c]=str[i];
    c++;
  }
  c=j;
  for(i=0;i<=c;i++){
    num=Add_HTable(word[i]);
  }
  printf("Hit =%d\n",num);
  while(1){
    printf("Type serch word\n q is End !Add is insert word.\n>");
    scanf("%[^\n]",str);
    ct=getchar();
    if(strcmp(str,"q")==0)
      break;
    if(strcmp(str,"!Add")==0)
      goto ADD_WORD;
    if(FindKeyWord(str))
      printf("Find\n");
    else
      printf("Not Found\n");
  }
  FreeKeyWord();
  return 0;
}
