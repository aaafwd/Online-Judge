/* @JUDGE_ID: 19899RK 10539 C++ "By Anadan" */
// Almost Prime Numbers
// Accepted (0.381 seconds using as much as 2652 kbytes)

#include <stdio.h>
#include <algorithm>
#define MAX 1000000000000

typedef long long qword;

int M;
char mask[1000000];
qword arr[81000];

int getindex(qword x, int flag){
	int i = 0, j = M - 1, k;

	while (i + 1 < j){
		k = (i + j) >> 1;
		if (arr[k] > x) j = k; else i = k;
	}

	if (flag){
		while (i < M && arr[i] < x) ++i;
		return i;
	}else{
		while (j >= 0 && arr[j] > x) --j;
		return j;
	}
}

int main(){
	int set, i, j;
	qword l, r;

	for (i = 2; i < 1000000; ++i){
		if (mask[i]) continue;
		for (j = i + i; j < 1000000; j += i) mask[j] = 1;
	}

	for (M = 0, i = 2; i < 1000000; ++i){
		if (mask[i]) continue;
		r = i;
		while (1){
			r *= i;
			if (r > MAX) break;
			arr[M++] = r;
		}
	}

	std::stable_sort(arr, arr + M - 1);

	scanf("%d", &set);
	while (set--){
		scanf("%lld%lld", &l, &r);
		printf("%d\n", getindex(r, 0) - getindex(l, 1) + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
