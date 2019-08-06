#include <stdio.h>
#include <stdlib.h>

#define SIZE 12345678

void initialize(char x[SIZE]);
void disp_array(char box[SIZE]);

int main(void)
{
  char *array;

  /* mallocを使ってメモリ（配列）を動的確保 */
  array = (char *)malloc(sizeof(char)*SIZE + 1);
  
  initialize(array);

  disp_array(array);

  return 0;
}

void initialize(char x[SIZE])
{
  int i;

  for (i=0; i<SIZE; i++) {
    x[i] = 'a';
  }
  array[i] = '\0';
}

void disp_array(char box[SIZE])
{
  int i;

  for (i=0; i<SIZE; i++) {
    printf("%c", box[i]);
  }
  printf("\n");
}
