/* @JUDGE_ID: 19899RK 202 C++ "By Anadan" */ 
// Repeating Decimals
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	char str[51]; str[50] = 0;
	int i, j, n, m, nz[3001], c;

	while (scanf("%d%d", &n, &m) == 2){
		for (i = 0; i < m; i++) nz[i] = 0;
		printf("%d/%d = %d.", n, m, n/m); n %= m;
		if (n == 0){
			printf("(0)\n   1 = number of digits in repeating cycle\n\n");
			continue;
		}
		for (i = 1, c = 0; ; i++, c++){
			if (nz[n]){
				j = nz[n] - 1;
				m = str[j]; str[j] = 0;
				printf("%s(", str);
				str[j] = m;
				if (c < 50) str[c] = 0;
				printf("%s", &str[j]);
				if (c >= 50) printf("...");
				printf(")\n   %d = number of digits in repeating cycle\n\n", i - nz[n]);
				break;
			}
			nz[n] = i; n *= 10;
			if (c < 50) str[c] = '0' + n / m;
			n %= m;
			if (n == 0){
				c++;
				if (c < 50) str[c] = 0;
				printf("%s(0)\n", str);
				printf("   1 = number of digits in repeating cycle\n\n");
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
