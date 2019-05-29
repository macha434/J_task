#include <stdio.h>

double calc_triangle(double base, double height);

int main(){
	double base, height, area;

	printf("三角形の底辺を入力してください。:");
	scanf("%lf", &base);

	printf("三角形の高さを入力してください。:");
	scanf("%lf", &height);

	area= calc_triangle(base, height);

	if(area== -1){
		printf("Inout error\n");
	}else{

		printf("三角形の面積は%fです。\n", area);
	}
}

double calc_triangle(double base, double height){
	double area;

	if(base< 0 || height< 0){
		area= -1;
	}else{

		area= base* height/ 2;
	}

	return area;
}
