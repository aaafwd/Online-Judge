/* @JUDGE_ID: 19899RK 10817 C++ "By Anadan" */
// Headmaster's Headache
// Accepted (0.367 seconds using as much as 416 kbytes)

#include <stdio.h>
#include <string.h>

struct Applicants {
	int c;
	char mask[8];
} pt[100];
int pow3[9], S, N;

int getState(int state, int index) {
	int i, j, res = state;
	for (i = 0; i < S; ++i) {
		j = state % 3;
		state /= 3;
		if (j && pt[index].mask[i]) res -= pow3[i];
	}
	return res;
}

int solve(int state) {
	int res[6561], i, j, s;

	memset(res, -1, pow3[S] * sizeof(int));
	res[state] = 0;

	for (i = 0; i < N; ++i) {
		if (res[0] != -1 && pt[i].c >= res[0]) continue;
		for (j = 1; j <= state; ++j) {
			if (res[j] == -1) continue;
			s = getState(j, i);
			if (res[s] == -1 || res[s] > res[j] + pt[i].c) {
				res[s] = res[j] + pt[i].c;
			}
		}
	}
	return res[0];
}

int main() {
	int M, c, i, state, sum;
	char mask[8];

	pow3[0] = 1;
	for (i = 1; i < 9; ++i) pow3[i] = pow3[i-1] * 3;

	while (scanf("%d%d%d", &S, &M, &N) == 3 && S) {
		sum = 0;
		memset(mask, 0, S);
		for (i = 0; i < M; ++i) {
			scanf("%d", &c);
			sum += c;
			while ((c = getchar()) != '\n') {
				if ('1' <= c && c <= '9') ++mask[c - '1'];
			}
		}

		for (i = 0; i < N; ++i) {
			memset(pt[i].mask, 0, sizeof(pt[i].mask));
			scanf("%d", &pt[i].c);
			while ((c = getchar()) != '\n') {
				if ('1' <= c && c <= '9') pt[i].mask[c - '1'] = 1;
			}
		}

		state = 0;
		for (i = 0; i < S; ++i) {
			if (mask[i] > 2) mask[i] = 2;
			state += (2 - mask[i]) * pow3[i];
		}

		sum += solve(state);
		printf("%d\n", sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
