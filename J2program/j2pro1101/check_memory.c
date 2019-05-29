#include <stdio.h>
#include <stdlib.h>

#define NUM 100000

int main(void)
{
  double *pt;
  int i, j;
  char enter;
  
  for (i=0; i<10; i++) {
    for (j=0; j<NUM; j++) {
      pt = (double *)malloc(sizeof(double)*NUM);
    }
    printf("\n");
    printf("stop!\n");
    printf("Please Enter key.\n");
    scanf("%c", &enter); 
  }
  
  return 0;
}
