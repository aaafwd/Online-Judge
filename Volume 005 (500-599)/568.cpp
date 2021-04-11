/* @JUDGE_ID: 19899RK 568 C++ "By Anadan" */
// Just the Facts
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i, j, n, res;
	while (scanf("%d", &n) > 0){
		if (n == 0){
			printf("    0 -> 1\n");
			continue;
		}

		for (i = res = 1; i <= n; i++){
			j = i;
			while (!(j % 5)){
				if (res == 2) res = 6;
				else if (res == 4) res = 2;
				else if (res == 6) res = 8;
				else if (res == 8) res = 4;
				j /= 5;
			}
			j %= 10;
			res = (res * j) % 10;
		}
		printf("%5d -> %d\n", n, res);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
