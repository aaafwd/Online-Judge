/* @JUDGE_ID: 19899RK 10810 C++ "By Anadan" */
// Ultra-QuickSort
// Accepted (1.201 seconds using as much as 4296 kbytes)

#include <stdio.h>

typedef long long qword;
int N, arr[500000], tmp[500000];

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

qword permutations(int i, int j) {
	int k, l, count = 0;
	qword res = 0;

	if (i >= j) return 0;
	k = (i+j) >> 1;
	l = k + 1;

	if (i < k) res += permutations(i, k);
	if (l < j) res += permutations(l, j);

	while (i <= k && l <= j) {
		if (arr[i] <= arr[l]) {
			tmp[count++] = arr[i++];
		} else {
			tmp[count++] = arr[l++];
			res += k - i + 1;
		}
	}
	while (i <= k) tmp[count++] = arr[i++];
	while (l <= j) tmp[count++] = arr[l++];
	while (count--) arr[j--] = tmp[count];

	return res;
}

int main(){
	int i;
	while (scanf("%d", &N) == 1 && N) {
		for (i = 0; i < N; ++i) myscanf(arr[i]);
		printf("%lld\n", permutations(0, N-1));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
