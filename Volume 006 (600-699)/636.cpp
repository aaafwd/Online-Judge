/* @JUDGE_ID: 19899RK 636 C++ "By Anadan" */
// Squares(III)
// Accepted (0.000 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>

long getnum(char *str, int i){
	char *p = str + strlen(str) - 1;
	long res = 0L, base = 1L;

	for (; p >= str; p--, base *= i){
		res += base * (*p - '0');
	}

	return res;
}

int main(){
	int i;
	long num;
	double tmp;
	char str[40], *p;

	while (scanf("%s\n", str) > 0){
		if ((str[0] == '0') && (str[1] == 0)) break;
		for (i = 2, p = str; *p; p++){
			if (*p - '0' >= i) i = *p - '0' + 1;
		}
		for (; i < 100; i++){
			num = getnum(str, i);
			tmp = sqrt((double)num);
			if (tmp == floor(tmp)) break;
		}
		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
