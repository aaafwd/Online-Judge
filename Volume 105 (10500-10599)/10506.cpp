/* @JUDGE_ID: 19899RK 10506 C++ "By Anadan" */
// Ouroboros
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, M;
char mask[65536], res[65537];

void solve(){
	int len = 1, i, j, prev, tmp, curr, count[10];

	for (i = 0; i < N; ++i) count[i] = 0;
	for (i = 0; i < M; ++i){
		len *= N;
		res[i] = '0';
	}

	memset(mask, 0, len);
	mask[0] = 1;
	prev = 0;
	tmp = len / N;

	res[i] = '0';
	count[0] = M;
	while (1){
		if (i == len){
			for (curr = prev, j = M - 1; j > 0; --j){
				curr = (curr - (res[len - 1 - j] - '0') * tmp) * N + res[M - 1 - j] - '0';
				if (mask[curr]) break;
			}

			if (j > 0){
				--i;
				mask[prev] = 0;
				--count[res[i] - '0'];
				prev = prev / N + (res[i - M] - '0') * tmp;
			}
			else break;
		}

		++res[i];
		if (res[i] - '0' >= N){
			--i;
			mask[prev] = 0;
			--count[res[i] - '0'];
			prev = prev / N + (res[i - M] - '0') * tmp;
			continue;
		}

		if (count[res[i] - '0'] == tmp) continue;
		curr = (prev - (res[i - M] - '0') * tmp) * N + res[i] - '0';
		if (mask[curr]) continue;
		prev = curr;
		mask[curr] = 1;
		++count[res[i] - '0'];
		res[++i] = '0' - 1;
	}

	res[len] = 0;
}

int main(){
	while (scanf("%d%d", &M, &N) == 2){
		solve();
		puts(res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
