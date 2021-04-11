/* @JUDGE_ID: 19899RK 10647 C++ "By Anadan" */
// Optimal House Placement
// Accepted (0.477 seconds using as much as 504 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long qword;
int arr[10000];

qword qsqr(qword x) { return x * x; }

int sort_function(const void *a, const void *b){
	if (*(int *)a < *(int *)b) return -1;
	return 1;
}

int main(){
	int N, i;
	qword ld, rd, L;
	double pos, best, tmp;

	while (scanf("%d", &N) == 1 && N){
		ld = rd = 0; best = -1;
		for (i = 0; i < N; ++i) scanf("%d", arr + i);
		qsort(arr, N, sizeof(int), sort_function);
		for (i = 1; i < N - 1; ++i) ld += qsqr(arr[i] - arr[i - 1]) * (i + 1);
		for (i = N - 2; i >= 0; --i){
			L = qsqr(arr[i+1] - arr[i]);
			tmp = double(L)*(i+1)*(N-i-1)/N;
			if (best == -1 || best >= ld+rd+tmp - 1e-12){
				best = ld+rd+tmp;
				pos = arr[i] + sqrt(L)*(N-i-1)/N;
			}

			if (i) ld -= qsqr(arr[i] - arr[i-1]) * i;
			rd += L * (N - i - 1);
		}

		printf("%.3lf\n", pos);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
