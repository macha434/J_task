#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000000

void initialize(char array[]);
void disp_array(int o, int a, int k, int s);
int oeda(char array[]);
int and(char array[]);
int kisarazu(char array[]);
int saikou(char array[]);

int main(void)
{
  char *array;

  int o, a, k, s;

  srand((unsigned)time(NULL));

  /* mallocを使ってメモリ（配列）を動的確保 */
  array = (char *)malloc(sizeof(char)*SIZE + 1);
 
  initialize(array);
  
  o= oeda(array);
  a= and(array);
  k= kisarazu(array);
  s= saikou(array);
 
  disp_array(o, a, k, s);

  return 0;
}

void initialize(char array[])
{
  int i;

  for (i=0; i<SIZE; i++) {
    array[i]= rand()% 26+ 'a';
  }
  array[i]= '\0';

  printf("%s\n", array);
}

int oeda(char array[])
{
	int i;
	int o= 0;
	char oeda[4];

	for(i=0; i<SIZE; i++){
		oeda[0]= oeda[1];
		oeda[1]= oeda[2];
		oeda[2]= oeda[3];
		oeda[3]= array[i];

		if(oeda[0]=='o' && oeda[1]=='e' && oeda[2]=='d' && oeda[3]== 'a'){
			o++;
		}
	}
	return o;
}

int and(char array[])
{
	int i;
	int a= 0;
	char and[3];
	for(i=0; i<SIZE; i++){
		and[0]= and[1];
		and[1]= and[2];
		and[2]= array[i];

		if(and[0]=='a' && and[1]=='n' && and[2]=='d'){
			a++;
		}
	}
	return a;
}

int kisarazu(char array[])
{
	int i, j, l= 0;
	int k= 0;
	char ans[]= "kisarazu";

	for(i=0; i<SIZE; i++){
		if(i<= 8){
			for(j= i- 8; j<= i; j++){
				if(array[j]!= ans[l]){
					break;
				}
		
				if(j== i){
					k++;
				}
				l++;
			}
			l= 0;
		}
	}
	return k;
}

int saikou(char array[])
{
	int i, j, k= 0;
	int s= 0, c= 0;
	char ans[15]= "saikounandayone";
		
	for(i=0; i<SIZE; i++){
		if(i>= 14){
			for(j= i- 14; j<= i; j++){
				if(array[j]!= ans[k]){
					break;
				}
				if(j== 15){
					c++;
				}
				k++;
			}
			k= 0;
		}
	}
	return c;
}

void disp_array(int o, int a, int k, int s)
{
  printf(" oedaが出た回数%d回\n andが出た回数%d回\n kisarazuが出た回数%d回\n", o, a, k);
  printf(" saikouが出た回数%d回\n", s);

}
