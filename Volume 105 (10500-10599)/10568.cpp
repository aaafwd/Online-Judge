/* @JUDGE_ID: 19899RK 10568 C++ "By Anadan" */
// n Group k
// Accepted (0.291 seconds using as much as 808 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long qword;

int N, K, G, group[16], sp;
qword count[31][31], C[31][31];
char res[10000][32], curr[32], *currp, mask[16];

void generate0();
void generate1(int i, int g);
void generate2(int i, int g);

qword gcd(qword a, qword b) {
	while (a && b) if (a > b) a %= b; else b %= a;
	return a + b;
}

void precalc() {
	int i, j, k;
	qword tmp;

	C[0][0] = 1;
	for (i = 1; i <= 30; ++i) {
		C[i][0] = C[i][i] = 1;
		for (j = 1; j < i; ++j) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}

	for (j = 1; j <= 30; ++j) {
		for (k = 0; k < j; ++k) {
			count[k][j] = 1;
			for (i = k + j; i <= 30; i += j) {
				tmp = gcd(C[i][j], (i/j));
				count[i][j] = count[i-j][j] / ((i/j)/tmp) * (C[i][j]/tmp);
			}
		}
	}
}

int sort_function(const void *a, const void *b) {
	return strcmp((char*)a, (char*)b);
}

void generate2(int i, int g) {
	if (group[g] == 0) {
		*currp++ = ' ';
		generate1(0, g+1);
		--currp;
		return;
	}

	for (; i < N; ++i) {
		if (mask[i] == 0) {
			mask[i] = 1;
			--group[g];
			*currp++ = 'A' + i;

			generate2(i+1, g);

			++group[g];
			mask[i] = 0;
			--currp;
		}
	}
}

void generate1(int i, int g) {
	if (g >= G) {
		*(currp - 1) = 0;
		strcpy(res[sp++] , curr);
		return;
	}

	for (; mask[i]; ++i);
	mask[i] = 1;
	*currp++ = 'A' + i;
	--group[g];

	generate2(i+1, g);

	mask[i] = 0;
	--currp;
	++group[g];
}

void generate0() {
	int i;

	sp = 0;
	currp = curr;
	G = (N+K-1) / K;
	memset(mask, 0, sizeof(mask));

	for (i = 0; i < G; ++i) group[i] = K;
	if (N % K) {
		for (i = 0; i < G; ++i) {
			group[i] = N % K;
			generate1(0, 0);
			group[i] = K;
		}
	} else {
		generate1(0, 0);
	}
}

int main() {
	int i;
	char str[16];

	precalc();

	while (scanf("%s", str) == 1 && strcmp(str, "END")) {
		scanf("%d%d", &N, &K);

		printf("%llu\n", count[N][K]);

		if (strcmp(str, "GENERATE") == 0) {
			generate0();
			qsort(res, sp, sizeof(res[0]), sort_function);
			for (i = 0; i < sp; ++i) puts(res[i]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
