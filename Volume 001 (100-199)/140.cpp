/* @JUDGE_ID: 19899RK 140 C++ "By Anadan" */ 
// Bandwidth
// Accepted (0.045 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, min;
char map[9][9], letters[9], curr[9], best[9], mask[26];

int getindex(char c){
	int i;
	for (i = 0; i < N; ++i) if (c == letters[i]) return i;
	return -1;
}

void generate(int n, int band){
	int i, j, k;

	if (band >= min) return;
	if (n == N){
		min = band;
		for (i = 0; i < N; ++i) best[i] = letters[curr[i]];
		return;
	}

	for (i = 0; i < N; ++i){
		if (mask[i]) continue;
		mask[i] = 1;

		curr[n] = i;
		for (k = band, j = 0; j < n; ++j){
			if (map[curr[j]][i] && k < n - j) k = n - j;
		}

		generate(n + 1, k);
		mask[i] = 0;
	}
}

int main(){
	int i, j;
	char str[128], *p;

	while (scanf("%s\n", str) == 1 && str[0] != '#'){
		N = 0;
		memset(mask, 0, 26);
		for (p = str; *p; ++p){
			if ('A' <= *p && *p <= 'Z' && mask[*p - 'A'] == 0){
				mask[*p - 'A'] = 1;
				++N;
			}
		}
		for (p = letters, i = 0; i < 26; ++i) if (mask[i]) *p++ = 'A' + i;
		for (i = 0; i < N; ++i) memset(map[i], 0, N);

		p = strtok(str, ";");
		while (p){
			i = getindex(*p);
			for (p += 2; *p; ++p){
				j = getindex(*p);
				map[i][j] = map[j][i] = 1;
			}

			p = strtok(NULL, ";");
		}

		memset(mask, 0, 26);
		min = 9;
		generate(0, 0);

		for (i = 0; i < N; ++i) printf("%c ", best[i]);
		printf("-> %d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
