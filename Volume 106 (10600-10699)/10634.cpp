/* @JUDGE_ID: 19899RK 10634 C++ "By Anadan" */
// Say NO to Memorization
// Accepted (0.074 seconds with low memory spent)

#include <stdio.h>
#define SZ 1001

typedef long long qword;
qword P[SZ][SZ], sum[SZ];

void myscanf(int &x){
	int i;
	while ((x = getchar()) < '0' || x > '9');
	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main() {
	int i, j;

	for (i = 0; i < SZ; ++i) sum[i] = P[0][i] = 1;
	for (i = 1; i < SZ; ++i) {
		if (i & 1) P[i][0] = 0;
		else { P[i][0] = 1; ++sum[0]; }
		for (j = 1; j < SZ; ++j) {
			P[i][j] = sum[j-1];
			sum[j] += sum[j-1];
		}
	}

	while (1) {
		myscanf(i); myscanf(j);
		if (!i && !j) break;
		printf("%lld\n", P[i][j]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
