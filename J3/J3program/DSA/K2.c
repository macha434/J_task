#include <stdio.h>

void sum_func(struct num1, struct num2);
void sub_func(struct num1, struct num2);
void mal_func(struct num1, struct num2);
void div_func(struct num1, struct num2);

struct C_num{
    int num;
    bool i_num;
};

int main(){
    struct C_num num1;
    struct C_num num2;

    num1.num= 5;
    num1.i_num= 0;

    num2.num= 4;
    num2.i_num= 1;

    sum_func(num1, num2);
    sub_func(num1, num2);
    mal_func(num1, num2);
    div_func(num1, num2);

    return 0;
}

void sum_func(struct num1, struct num2){
    if (num1.i_num ^ num2.i_num){

        printf("sum : %d", num1.num+ num2.num);
    }else {

        printf("")
    }
}
