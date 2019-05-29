#include <stdio.h>
#include <stdlib.h>

#define NUM 25

struct status {
  int no;
  int japanese;
  int english;
  int math;
  int sum;
  double ave;
};

void initialize(struct status students[]);
void disp(struct status students[]);
void Eng_no(struct status students[]);
void Eng_point(struct status students[]);
void Eng_ave(struct status students[]);
void synthesis(struct status students[]);
void sort(struct status students[]);

int main(void)
{
  struct status students[NUM];
  int index;
  double ave_math;
  
  srand(208);

  initialize(students);
  disp(students);

  Eng_no(students);

  Eng_point(students);

  Eng_ave(students);

  synthesis(students);

  sort(students);
  //disp(students);
  
  return 0;
}

void initialize(struct status students[])
{
  int i;

  for (i=0; i<NUM; i++) {
    students[i].no = 4401+i;
    students[i].japanese = rand()%101;
    students[i].english = rand()%101;
    students[i].math = rand()%101;
    students[i].sum = students[i].japanese+ students[i].english+ students[i].math; 
    students[i].ave = 0.0;
  }
}

void disp(struct status students[])
{
  int i;

  printf("No    Ja  En  Ma  | Sum  Ave\n");
  for (i=0; i<NUM; i++) {
    printf("%d %3d %3d %3d  | %3d  %3.1f\n",
           students[i].no,
           students[i].japanese,
           students[i].english,
           students[i].math,
           students[i].sum,
	   students[i].ave);
  }
  printf("\n");
}

void Eng_no(struct status students[]){
	int i;
	int tmp= 0;

	for (i=0; i<NUM; i++){

		if(students[tmp].english< students[i].english){
			tmp= i;
		}
	}
	printf("\n\nEnglish Max Point No= %d\n\n", students[tmp].no);
}

void Eng_point(struct status students[]){
	int i;
	int tmp= 0;

	for (i=0; i<NUM; i++){

		if(students[tmp].english< students[i].english){
			tmp= i;
		}
	}
	printf("\n\nEnglish Max Point= %d\n\n", students[tmp].english);
}

void Eng_ave(struct status students[]){
	int i;
	int sum= 0;

	for (i=0; i<NUM; i++){
		sum+= students[i].english;
	}

	printf("\n\nEnglish Average Point= %d\n\n", sum/ NUM);

}

void synthesis(struct status students[]){
	int i;
	int tmp= 0;

	for (i=0; i<NUM; i++){

		if(students[tmp].sum< students[i].sum){
			tmp= i;
		}
	}

	printf("\n\nSynthesis Max Each Subject Point\n");
	printf("Jpa= %d\nEng= %d\nMath= %d\n\n", students[tmp].japanese, students[tmp].english, students[tmp].math);
}

void sort(struct status student[]){
	int i, j;

	for (i=0; i<NUM; i++){
		tmp= i;
		for (j=NUM- 1; j>i; j--){

			if(students[j-1].sum< students[j].sum){
				swap(students[j-i].sum, students[j].sum)

	}
}
