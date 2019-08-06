#include <stdio.h>


void func(int *a, int *b);

int main(){
	int x= 1, y= 2;

	func(&x, &y);

	printf("x=%d, y=%d\n", x, y);

	return 0;
}

void func(int *a, int *b){
	int *tmp;

	tmp= a;

	printf("a= %p\nb= %p\nt= %p\n", a, b, tmp);

	a= b;

	printf("a= %p\nb= %p\nt= %p\n", a, b, tmp);

	b= tmp;

	printf("a= %p\nb= %p\nt= %p\n", a, b, tmp);
}
