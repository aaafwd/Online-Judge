/* @JUDGE_ID: 19899RK 10018 C++ "By Anadan" */
// Reverse and Add
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long dword;

dword reverse(dword a){
	dword res = 0L;

	while (a){
		res *= 10;
		res += a % 10;
		a /= 10;
	}

	return res;
}

int main(){
	int i, N;
	dword x, y;
	scanf("%d", &N);

	while(N--){
		scanf("%lu", &x);
		x += reverse(x);
		for (i = 1; ;i++, x += y){
			y = reverse(x);
			if (x == y) break;
		}

		printf("%d %lu\n", i, x);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
