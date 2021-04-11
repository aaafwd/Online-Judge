/* @JUDGE_ID: 19899RK 575 C++ "By Anadan" */ 
// Skew Binary
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int main(){
	int i;
	long res, w;
	char str[128];

	while (scanf("%s\n", str) > 0){
		if (str[0] == '0') break;
		res = 0L; w = 2L;
		i = strlen(str) - 1;
		while (str[i] == '0'){
			w <<= 1;
			i--;
		}
		res += w - 1;
		if (str[i] == '2') res <<= 1;
		for (i--, w <<= 1; i >= 0; i--, w <<= 1){
			if (str[i] == '1') res += w - 1;
		}
		printf("%ld\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
