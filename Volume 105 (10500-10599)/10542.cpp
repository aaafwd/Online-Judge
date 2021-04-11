/* @JUDGE_ID: 19899RK 10542 C++ "By Anadan" */
// Hyper-drive
// Algorithm: principle of inclusion/exclusion (PIE)
// Accepted (0.139 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

typedef long long qword;

int N;
unsigned int nums[10];
char mask[10];

unsigned gcd(unsigned a, unsigned b){
	while (a && b) if (a > b) a %= b; else b %= a;
	return a + b;
}

qword generate(int i, int rest, unsigned int curr) {
	qword res = 0;

	if (rest-- == 0) return curr;
	for (; i < N - rest; ++i) {
		if (mask[i]) continue;
		mask[i] = 1;
		res += generate(i+1, rest, gcd(curr, nums[i]));
		mask[i] = 0;
	}

	return res;
}

int main() {
	int set, cs = 0, i, x;
	qword arr[10], res;

	memset(mask, 0, sizeof(mask));

	scanf("%d", &set);
	while (set--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i) { scanf("%d", &x); arr[i] = x; }
		for (i = 0; i < N; ++i) {
			scanf("%d", &x);
			arr[i] -= x;
			if (arr[i] < 0) arr[i] = -arr[i];
			nums[i] = (unsigned int)arr[i];
		}

		res = 0;
		for (i = 0; i < N; ++i) {
			if (i & 1) res -= generate(0, i+1, 0);
			else res += generate(0, i+1, 0);
		}

		printf("Case %d: %lld\n", ++cs, res);

	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
