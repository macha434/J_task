#include <stdio.h>

int main(){
	char num[]="prhzizafplftblfplfglthvmnlmtzpplf\0";
	int i, j, k;
	char cha;

	for(i=0; i<26; i++){
		for(j=0; num[j]!= '\0'; j++){
			num[j]+= 1;
			if(num[j]> 'z'){
				num[j]-= 26;
			}
			if(num[i]== 'k'){
				k++;
			}
		}
		if(k>0){
		printf("%s\n", num);
		}
	}

	return 0;
}
