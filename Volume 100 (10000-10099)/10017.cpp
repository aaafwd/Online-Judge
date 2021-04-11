/* @JUDGE_ID: 19899RK 10017 C++ "By Anadan" */ 
// The Never Ending Towers of Hanoi
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>

int peg[3][300], sp[3];

void outstate(){
	int i, j;

	for (i = 0; i < 3; ++i){
		printf("%c=>", 'A' + i);
		if (sp[i] > 1){
			printf("  ");
			for (j = 1; j < sp[i]; ++j) printf(" %d", peg[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int main(){
	int set = 0, i, j, n, m, one, flag;

	peg[0][0] = peg[1][0] = peg[2][0] = 10000;
	while (scanf("%d%d\n", &n, &m) == 2 && n){
		sp[0] = sp[1] = sp[2] = 1;
		while (n) peg[0][sp[0]++] = n--;

		printf("Problem #%d\n\n", ++set);
		outstate();
		flag = (peg[0][1] & 1);
		for (one = 0, n = 1; n <= m; ++n){
			if (n & 1){
				--sp[one];
				if (flag){
					if (one == 0) i = 2;
					else if (one == 2) i = 1;
					else i = 0;
				}else i = (one + 1) % 3;
				peg[i][sp[i]++] = 1;
				one = i;
			}else{
				if (one) i = 0; else i = 1;
				j = 3 - i - one;
				if (peg[i][sp[i] - 1] > peg[j][sp[j] - 1]) i ^= j ^= i ^= j;
				peg[j][sp[j]++] = peg[i][--sp[i]];
			}

			outstate();
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
