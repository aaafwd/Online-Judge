/* @JUDGE_ID: 19899RK 10107 C++ "By Anadan" */
// What is the Median?
// Accepted (0.060 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef unsigned long dword;

int main(){
	int i, j, k, N;
	dword pt[10000], x;

	if (scanf("%lu", &x) <= 0) return 0;
	pt[0] = x;
	printf("%lu\n", x);

	if (scanf("%lu", &x) <= 0) return 0;
	printf("%lu\n", (x + pt[0]) >> 1);
	if (x >= pt[0]) pt[1] = x;
	else{
		pt[1] = pt[0];
		pt[0] = x;
	}

	N = 2;
	while (scanf("%lu", &x) > 0){
		if (x >= pt[N - 1]) pt[N] = x;
		else if (x <= pt[0]){
			memmove(pt + 1, pt, N * sizeof(dword));
			pt[0] = x;
		}else{
			i = 0;
			j = N - 1;
			while (j > i + 1){
				k = (i + j) >> 1;
				if (pt[k] > x) j = k;
				else i = k;
			}
			memmove(pt + j + 1, pt + j, (N - j) * sizeof(dword));
			pt[j] = x;
		}

		++N;
		if (N & 1) printf("%lu\n", pt[N >> 1]);
		else{
			x = (pt[N >> 1] + pt[(N >> 1) - 1]) >> 1;
			printf("%lu\n", x);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
