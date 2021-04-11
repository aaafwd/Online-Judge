/* @JUDGE_ID: 19899RK 10473 C++ "By Anadan" */ 
// Simple Base Conversion
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>

int main(){
	int x;
	char str[16];

	while (scanf("%s\n", str) == 1){
		if (str[0] == '-') break;
		if (str[1] == 'x'){
			sscanf(str + 2, "%x", &x);
			printf("%d\n", x);
		}else{
			sscanf(str, "%d", &x);
			printf("0x%X\n", x);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
