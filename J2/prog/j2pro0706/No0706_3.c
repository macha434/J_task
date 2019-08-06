#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void initialize(char array[SIZE]);
void disp_array(int c);
int count(char array[SIZE]);

int main(void)
{
  char *array;
  int c;

  srand((unsigned)time(NULL));

  /* mallocを使ってメモリ（配列）を動的確保 */
  array = (char *)malloc(sizeof(char)*SIZE + 1);
  
  initialize(array);
  
  c= count(array);

  disp_array(c);

  return 0;
}

void initialize(char array[SIZE])
{
  int i;

  for (i=0; i<SIZE; i++) {
    array[i]= rand()% 26+ 'a';
  }
}

int count(char array[SIZE])
{
	int i;
	int c;
	char oeda[4];
	for(i=0; i<SIZE; i++){
		oeda[0]= oeda[1];
		oeda[1]= oeda[2];
		oeda[2]= oeda[3];
		oeda[3]= array[i];

		if(oeda[0]=='o' && oeda[1]=='e' && oeda[2]=='d' && oeda[3]== 'a'){
			c++;
		}
	}
	return c;
}

void disp_array(int c)
{
  printf("oedaが出た回数%d回\n", c);
  
}
