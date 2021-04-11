/* @JUDGE_ID: 19899RK 10830 C++ "By Anadan" */
// A New Function
// Accepted (0.203 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

typedef long long qword;

// CSOD(N) = (N/2)*2 + (N/3)*3 + ... + (N/N)*N - sum(2,N)
qword CSOD(int N) {
	int i, j, rest, toi = (int)sqrt(N);
	qword res = -qword(N+2)*(N-1)/2;

	for (i = 2; i <= toi; ++i) res += qword(N/i)*i;
	while (i <= N) {
		rest = N/i;
		j = N/rest;
		res += ((qword(i)+j)*(j-i+1)/2)*rest;
		i = j+1;
	}

	return res;
}

int main() {
	int set = 0, N;

	while (scanf("%d", &N) == 1 && N) {
		printf("Case %d: %llu\n", ++set, CSOD(N));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
