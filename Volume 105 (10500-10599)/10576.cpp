/* @JUDGE_ID: 19899RK 10576 C++ "By Anadan" */
// Problem B: Y2K Accounting Bug
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int a, s, d, sum;

	while (scanf("%d%d", &s, &d) == 2){
		sum = s*4 - d;
		for (a = 4; a && sum >= 0; --a, sum -= s + d);
		if (a == 0) puts("Deficit");
		else{
			if (a == 1) sum = s*3 - d*9;
			else sum = s*(2+a+a) - d*(10-a-a);
			if (sum <= 0) puts("Deficit");
			else printf("%d\n", sum);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
