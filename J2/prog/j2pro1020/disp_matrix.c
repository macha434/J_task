#include <stdio.h>

void set_matrix(int ma[][5]);
void disp_matrix(int ma[][5]);

int main(void)
{
  int ma[2][5];

  set_matrix(ma);
  
  disp_matrix(ma);

  return 0;
}

void set_matrix(int m[][5])
{
  int i, j;
  int count;

  count = 0;
  for (i=0; i<2; i++) {
    for (j=0; j<5; j++) {
      m[i][j] = count;
      count++;
    }
  }
}

void disp_matrix(int m[][5])
{
  int i, j;

  for (i=0; i<2; i++) {
    for (j=0; j<5; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }    
  printf("\n");

}
