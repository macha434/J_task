#include "niusb6501.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define indi 5
#define value 32

void problem();
void dynamic();
char sel_place(char B_val, char i);
char chenge_line_val(char place, char i);
char check_finish();
void wait();
char portA= (unsigned)(0x00);
char portB= (unsigned)(0x01);
char portC= (unsigned)(0x02);
char col= 0;
char num= 0;
char pro_val= 0;
char prob_val[indi][indi];
char prob[10][indi][indi]={
				{
					{0,0,0,1,0},
					{1,1,0,1,0},
					{0,0,0,0,0},
					{0,1,0,1,1},
					{0,1,0,0,0}
				},
				{
					{0,1,0,1,0},
					{1,0,1,0,1},
					{0,1,0,1,0},
					{1,0,1,0,1},
					{0,1,0,1,0}
				},
				{
					{1,0,1,0,1},
					{0,1,0,1,0},
					{0,1,1,1,0},
					{1,0,1,0,1},
					{1,1,0,1,1}
				},
				{
					{1,0,1,0,1},
					{0,0,0,0,0},
					{1,0,1,0,1},
					{0,0,0,0,0},
					{1,0,1,0,1}
				},
				{
					{0,1,1,1,0},
					{0,0,1,1,0},
					{0,1,0,1,0},
					{0,1,1,0,0},
					{0,1,1,1,0}
				},
				{
					{0,1,1,0,0},
					{0,0,1,0,1},
					{1,1,0,1,1},
					{1,0,1,0,0},
					{0,0,1,1,0}
				},
				{
					{1,1,1,1,1},
					{1,1,1,1,1},
					{1,1,0,1,1},
					{1,1,1,1,1},
					{1,1,1,1,1}
				},
				{
					{0,1,1,1,0},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{0,1,1,1,0}
				},
				{
					{1,1,1,1,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,0,0,0,1},
					{1,1,1,1,1}
				},
				{
					{0,0,1,0,0},
					{0,0,1,0,0},
					{1,1,0,1,1},
					{0,0,1,0,0},
					{0,0,1,0,0}
				}
			};

int main(){
	srand ((unsigned)time(NULL));

	num++;
	if(num== 10){
		num= 0;
	}

	init_device();
	set_io_mode(0xFF, 0xFF, 0xFF);

	problem();

	while(1){
		dynamic();
	}

	printf("error\n");
	return 1;
}

void problem(){
	int i, j;
	int p;

	for(i= 0; i< indi; i++){
		for(j= 0; j< indi; j++){
			switch(i){
				case 0:
					p= pow(2, 3);
				case 1:
					p= pow(2, 4);
				case 2:
					p= pow(2, 5);
				case 3:
					p= pow(2, 6);
				case 4:
					p= pow(2, 7);

			}
			prob_val[i][j]= prob[num][i][j];
			pro_val+= prob[num][i][j]+ p;
		}
	}
}

void dynamic(){
	int i;
	int B_val;

	for(i= 0; i< indi; i++){
		write_port(portA, prob_val+ i);
		write_port(portB, i);

		B_val= read_port(portB);

		sel_place(B_val, i);
	}
}

char sel_place(char B_val, char i){
	char place;

	B_val-= i;

	switch(i){
		case 0:
			switch(B_val){
				case 0x08:
					place= 0;
				case 0x10:
					place= 1;
				case 0x20:
					place= 2;
				case 0x40:
					place= 3;
				case 0x80:
					place= 4;
			}

		case 1:
			switch(B_val){
				case 0x08:
					place= 5;
				case 0x10:
					place= 6;
				case 0x20:
					place= 7;
				case 0x40:
					place= 8;
				case 0x80:
					place= 9;
			}

		case 2:
			switch(B_val){
				case 0x08:
					place= 10;
				case 0x10:
					place= 11;
				case 0x20:
					place= 12;
				case 0x40:
					place= 13;
				case 0x80:
					place= 14;
			}

		case 3:
			switch(B_val){
				case 0x08:
					place= 15;
				case 0x10:
					place= 16;
				case 0x20:
					place= 17;
				case 0x40:
					place= 18;
				case 0x80:
					place= 19;
			}

		case 4:
			switch(B_val){
				case 0x08:
					place= 20;
				case 0x10:
					place= 21;
				case 0x20:
					place= 22;
				case 0x40:
					place= 23;
				case 0x80:
					place= 24;
			}
	}
	chenge_line_val(place, i);
	check_finish();
}

char chenge_line_val(char place, char i){
	int place1, place2, place3, place4;

	place1= place- indi;
	place2= place- 1;
	place3= place+ 1;
	place4= place+ indi;

	switch(place){
		case 0:
			switch(prob_val[i][place]){
				case 0:
					prob_val[i][place]++;
					return 0;
				case 1:
					prob_val[i][place]--;
					return 0;
			}
			switch(prob_val[i][place3]){
				case 0:
					prob_val[i][place3]++;
					return 0;
				case 1:
					prob_val[i][place3]--;
					return 0;
			}
			switch(prob_val[i+ 1][place4]){
				case 0:
					prob_val[i+1][place4]++;
					return 0;
				case 1:
					prob_val[i+1][place4]--;
					return 0;
			}
		case 1:
		case 2:
		case 3:
			switch(prob_val[i][place]){
				case 0:
					prob_val[i][place]++;
					return 0;
				case 1:
					prob_val[i][place]--;
					return 0;
			}
			switch(prob_val[i][place2]){
				case 0:
					prob_val[i][place1]++;
					return 0;
				case 1:
					prob_val[i][place1]--;
					return 0;
			}
			switch(prob_val[i][place3]){
				case 0:
					prob_val[i][place2]++;
					return 0;
				case 1:
					prob_val[i][place2]--;
					return 0;
			}
			switch(prob_val[i+ 1][place4]){
				case 0:
					prob_val[i+1][place4]++;
					return 0;
				case 1:

					prob_val[i+1][place4]--;
					return 0;
			}

		case 5:
		case 10:
		case 15:
			switch(prob_val[i][place]){
				case 0:
					prob_val[i][place]++;
					return 0;
				case 1:
					prob_val[i][place]--;
					return 0;
			}
			switch(prob_val[i- 1][place1]){
				case 0:
					prob_val[i-1][place1]++;
					return 0;
				case 1:
					prob_val[i-1][place1]--;
					return 0;
			}
			switch(prob_val[i][place2]){
				case 0:
					prob_val[i][place2]++;
					return 0;
				case 1:
					prob_val[i][place2]--;
					return 0;
			}
			switch(prob_val[i][place3]){
				case 0:
					prob_val[i][place3]++;
					return 0;
				case 1:
					prob_val[i][place3]--;
					return 0;
			}
			switch(prob_val[i+ 1][place4]){
				case 0:
					prob_val[i+1][place4]++;
					return 0;
				case 1:
					prob_val[i+1][place4]--;
					return 0;
			}
		case 9:
		case 14:
		case 19:
			switch(prob_val[i][place]){
				case 0:
					prob_val[i][place]++;
					return 0;
				case 1:
					prob_val[i][place]--;
					return 0;
			}
			switch(prob_val[i- 1][place1]){
				case 0:
					prob_val[i-1][place1]++;
					return 0;
				case 1:
					prob_val[i-1][place1]--;
					return 0;
			}
			switch(prob_val[i][place3]){
				case 0:
					prob_val[i][place3]++;
					return 0;
				case 1:
					prob_val[i][place3]--;
					return 0;
			}
			switch(prob_val[i+ 1][place4]){
				case 0:
					prob_val[i+1][place3]++;
					return 0;
				case 1:
					prob_val[i+1][place3]--;
					return 0;
			}
		case 6:
		case 7:
		case 8:
		case 11:
		case 12:
		case 13:
		case 16:
		case 17:
		case 18:
			switch(prob_val[i][place]){
				case 0:
					prob_val[i][place]++;
					return 0;
				case 1:
					prob_val[i][place]--;
					return 0;
			}
			switch(prob_val[i- 1][place1]){
				case 0:
					prob_val[i-1][place1]++;
					return 0;
				case 1:
					prob_val[i-1][place1]--;
					return 0;
			}
			switch(prob_val[i][place2]){
				case 0:
					prob_val[i][place2]++;
					return 0;
				case 1:
					prob_val[i][place2]--;
					return 0;
			}
			switch(prob_val[i][place3]){
				case 0:
					prob_val[i][place3]++;
					return 0;
				case 1:
					prob_val[i][place3]--;
					return 0;
			}
			switch(prob_val[i+ 1][place4]){
				case 0:
					prob_val[i+1][place4]++;
					return 0;
				case 1:
					prob_val[i+1][place4]--;
					return 0;
			}
	}
}

char check_finish(){
	int i, j;

	for(i= 0; i< indi; i++){
		for(j= 0; j< indi; j++){
			if(prob_val[i][j]!= 1){
				break;
			}
		}
		if(prob_val[i][j]!= 1){
			break;
		}
	}

	if(i== 5 && j== 5){
		wait();
	}
}

void wait(){
	char portC_val, C_val;

	while(1){
		portC_val= read_port(portC);

		C_val= portC_val- col- 0xF8;

		if(C_val== 0){
			main();
		}
	}
}
