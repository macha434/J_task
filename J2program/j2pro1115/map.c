#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int **map;
  int xSize, ySize;
  int x, y;
  
  printf("map size(ySize)=");
  scanf("%d", &ySize);
  
  printf("map size(xSize)=");
  scanf("%d", &xSize);
  
  map = (int **)malloc(sizeof(int *) * ySize);
  for (y=0; y<ySize; y++) {
    map[y] = (int *)malloc(sizeof(int) * xSize);
  }
  
  for (y=0; y<ySize; y++) {
    for (x=0; x<xSize; x++) {
      map[y][x] = 8;
    }
  }
  
  for (y=0; y<ySize; y++) {
    for (x=0; x<xSize; x++) {
      printf("%d", map[y][x]);
    }
    printf("\n");
  }
  
  for (y=0; y<ySize; y++) {
    free(map[y]);
  }
  free(map);

  return 0;
}
