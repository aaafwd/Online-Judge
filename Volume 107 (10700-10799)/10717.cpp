/* @JUDGE_ID: 19899RK 10717 C++ "By Anadan" */
// Mint
// Accepted (2.127 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

typedef unsigned long long qword;

int N;
qword arr[64], total, min, max;

qword gcd(qword x, qword y) {
	while (x && y) if (x > y) x %= y; else y %= x;
	return x + y;
}

qword lcd(qword x, qword y) {
	return x*y / gcd(x,y);
}

void generate(int i, int count, qword curr) {
	if (min == total) return;

	if (count >= 4) {
		qword x = (total / curr) * curr;

		if (x == total) {
			min = max = x;
		} else {
			if (min < x) min = x;
			x += curr;
			if (max > x) max = x;
		}
		return;
	}

	for (; i < N; ++i) {
		generate(i+1, count+1, lcd(curr, arr[i]));
	}
}

int main() {
	int T, i;

	while (scanf("%d%d", &N, &T) == 2 && N) {
		for (i = 0; i < N; ++i) scanf("%llu", &arr[i]);
		while (T--) {
			scanf("%llu", &total);
			min = 0;
			max = qword(-1);
			generate(0, 0, 1);
			printf("%llu %llu\n", min, max);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
