/* @JUDGE_ID: 19899RK 696 C++ "By Anadan" */
// How Many Knights
// Accepted (0.150 seconds using as much as 388 kbytes)

#include <stdio.h>

int main(){
	int m, n, min, max;
	long res;

	while(scanf("%d%d", &m, &n) > 0){
		if ((!m) && (!n)) break;
		if (m > n) { min = n; max = m; } else { min = m; max = n; }
		if (min == 1) res = (long)max;
		else if (min == 2){
			res = ((long(max) + 3L) >> 2) << 2;
			if ((max & 3) == 1) res -= 2L;
		}
		else res = (long(min) * long(max) + 1L) >> 1;
		printf("%ld knights may be placed on a %d row %d column board.\n", res, m, n);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
