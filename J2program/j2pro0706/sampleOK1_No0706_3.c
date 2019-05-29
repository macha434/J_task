#include <stdio.h>
#include <stdlib.h>

#define SIZE 12345678

void initialize(char array[SIZE]);
void disp_array(char array[SIZE]);

int main(void)
{
  char *array;

  /* mallocを使ってメモリ（配列）を動的確保 */
  array = (char *)malloc(sizeof(char)*SIZE + 1);
  
  initialize(array);

  disp_array(array);

  return 0;
}

void initialize(char array[SIZE])
{
  int i;

  for (i=0; i<SIZE; i++) {
    array[i] = 'a';
  }
}

void disp_array(char array[SIZE])
{
  int i;

  for (i=0; i<SIZE; i++) {
    printf("%c", array[i]);
  }
  printf("\n");
}
