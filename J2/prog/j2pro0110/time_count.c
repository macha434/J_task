#include <stdio.h>
#include <time.h>

#define MAX 10000

int main(void)
{
  int i, j, k;
  clock_t start, end;
  double req_time;

  start = clock();

  printf("running...\n");
  for (i=0; i<MAX; i++) {
    for (j=0; j<MAX; j++) {
      for (k=0; k<MAX; k++) {
	// nop (no operation)
      }
    }
  }
  
  end = clock();

  req_time = (double)(end-start)/CLOCKS_PER_SEC;
  
  printf("req_time=%f\n", req_time);

  return 0;
}
