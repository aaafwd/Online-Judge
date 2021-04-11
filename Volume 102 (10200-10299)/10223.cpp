/* @JUDGE_ID: 19899RK 10223 C++ "By Anadan" */
// How many nodes ?
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int i;
	unsigned long c[20], n;

	for (c[0] = 0, c[1] = 1, i = 2; i < 20; ++i)
		c[i] = (c[i - 1] << 2) - c[i - 1] * 6 / (i + 1);

	while (scanf("%lu\n", &n) == 1){
		for (i = 0; c[i] < n; i++);
		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
