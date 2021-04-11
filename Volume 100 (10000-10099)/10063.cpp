/* @JUDGE_ID: 19899RK 10063 C++ "By Anadan" */
// Knuth's Permutation
// Accepted (0.330 seconds using as much as 384 kbytes)

#include <stdio.h>

char str[10];
int len, perm[10], tmp;

void generate(int n){
	int i;

	if (n == len){
		while (n--) putchar(str[perm[n]]);
		putchar('\n');
		return;
	}

	perm[n] = n;
	generate(n + 1);
	for (i = n - 1; i >= 0; --i){
		perm[i] ^= perm[i + 1] ^= perm[i] ^= perm[i + 1];
		generate(n + 1);
	}

	tmp = perm[0];
	for (i = 0; i < n; ++i) perm[i] = perm[i + 1];
	perm[n] = tmp;
}

int main(){
	char flag = 0;
	while (scanf("%s\n", str) == 1){
		if (flag) putchar('\n'); else flag = 1;
		for (len = 0; str[len]; ++len);
		generate(0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
