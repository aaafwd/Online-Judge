/* @JUDGE_ID: 19899RK 10819 C++ "By Anadan" */
// Trouble of 13-Dots
// Accepted (0.023 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

// M <= 1800 || M >= 2000
void solve1(int M, int N) {
	int res[512], i, p, f, maxRes;

	if (M > 1800) M += 200;
	memset(res, -1, sizeof(res));

	res[0] = maxRes = 0;
	while (N--) {
		scanf("%d%d", &p, &f);
		for (i = maxRes; i >= 0; --i) {
			if (res[i] == -1) continue;
			if ((res[i+f] == -1 || res[i+f] > res[i] + p) &&
				res[i] + p <= M)
			{
				res[i+f] = res[i] + p;
				if (maxRes < i+f) maxRes = i+f;
			}
		}
	}

	printf("%d\n", maxRes);
}

// 1801 <= M <= 1999
void solve2(int M, int N) {
	int res[2200], i, p, f, maxRes;

	M += 200;
	memset(res, -1, sizeof(res));

	res[0] = maxRes = 0;
	while (N--) {
		scanf("%d%d", &p, &f);
		for (i = maxRes; i >= 0; --i) {
			if (res[i] == -1) continue;
			if (i+p <= M && (res[i+p] == -1 || res[i+p] < res[i]+f)) {
				res[i+p] = res[i] + f;
				if (maxRes < i+p) maxRes = i+p;
			}
		}
	}

	maxRes = 0;
	for (i = M; i >= 0; --i) {
		if (res[i] == -1) continue;
		if (M - 200 < i && i <= 2000) continue;
		if (maxRes < res[i]) maxRes = res[i];
	}

	printf("%d\n", maxRes);
}

int main() {
	int M, N;

	while (scanf("%d%d", &M, &N) == 2) {
		if (M <= 1800 || M >= 2000) solve1(M, N);
		else solve2(M, N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
