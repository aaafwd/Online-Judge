/* @JUDGE_ID: 19899RK 10790 C++ "By Anadan" */
// How Many Points of Intersection?
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

typedef unsigned long long qword;

int main() {
	int set = 0, a, b;
	qword res;

	while (scanf("%d%d", &a, &b) == 2 && a) {
		res = a*(a-1)/2;
		res *= b*(b-1)/2;
		printf("Case %d: %llu\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
