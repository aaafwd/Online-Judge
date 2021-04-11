/* @JUDGE_ID: 19899RK 10633 C++ "By Anadan" */
// Rare Easy Problem
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;

int main(){
	int i, flag;
	qword x;

	while (scanf("%lld", &x) == 1 && x){
		for (flag = 0, i = 9; i >= 0; --i){
			if ((x - i) % 9) continue;
			if (flag) putchar(' '); else flag = 1;
			printf("%lld", ((x - i) / 9) * 10 + i);
		}
		putchar('\n');
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
