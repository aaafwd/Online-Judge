/* @JUDGE_ID: 19899RK 10244 C++ "By Anadan" */
// First Love!!!
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef long long qword;

char str[8], beadstr[10001], mask[10001];
int len, N;

void solve(int size) {
	int i, curr = 0, tmp, coeff = (size+1-N) / len;

	memset(beadstr, 0, sizeof(beadstr));
	memset(mask, 0, sizeof(mask));
	mask[0] = 1;

	for (i = N; i < size; ++i) {
		tmp = (curr - beadstr[i-N]*coeff)*len;
		for (beadstr[i]; beadstr[i] < len; ++beadstr[i]) {
			if (!mask[tmp + beadstr[i]]) {
				mask[tmp + beadstr[i]] = 1;
				break;
			}
		}
		if (beadstr[i] < len) curr = tmp + beadstr[i];
		else {
			mask[curr] = 0;
			beadstr[i--] = 0;
			curr = (curr - beadstr[i])/len + beadstr[i-N]*coeff;
			++beadstr[i--];
		}
	}

	for (i = 0; i < size; ++i) beadstr[i] = str[beadstr[i]];
	puts(beadstr);
}

int main() {
	int i;
	qword pow3[21], res;

	pow3[0] = 1;
	for (i = 1; i < 21; ++i) pow3[i] = pow3[i-1]*3;

	while (scanf("%s%d", str, &N) == 2) {
		len = strlen(str);
		if (len == 1) {
			printf("%d\n", N);
			for (i = 0; i < N; ++i) putchar(str[0]);
			putchar('\n');
			continue;
		}

		if (len == 2) res = (1<<N)+N-1;
		else if (len == 3) res = pow3[N]+N-1;
		else if (len == 4) res = (qword(1)<<(2*N))+N-1;
		printf("%lld\n", res);

		if (res < 10001) solve((int)res);
		else puts("TOO LONG TO PRINT.");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
