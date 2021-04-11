/* @JUDGE_ID: 19899RK 124 C++ "By Anadan" */
// Following Orders
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
char map[26][26], letters[26], mask[26], res[27];

int sort_function(const void *a, const void *b){
	if (*((char *)a) < *((char *)b)) return -1;
	return 1;
}

void generate_orders(int n){
	int i, j;
	char sav[26];

	if (n == N){
		res[n] = 0;
		printf("%s\n", res);
		return;
	}

	for (i = 0; i < N; ++i){
		if (mask[i]) continue;
		for (j = 0; j < N; ++j) if (map[j][i]) break;
		if (j < N) continue;
		memcpy(sav, map[i], N);
		memset(map[i], 0, N);
		++mask[i];
		res[n] = letters[i];
		generate_orders(n + 1);
		--mask[i];
		memcpy(map[i], sav, N);
	}
}

int getindex(char c){
	int i;
	for (i = 0; i < N; ++i) if (letters[i] == c) return i;
	letters[N] = c;
	return N++;
}

int main(){
	char str[1024], q[2], w[2], *p, flag = 0;
	int off;

	while (gets(str)){
		if (flag) putchar('\n'); else flag = 1;
		for (N = 0; N < 26; ++N) memset(map[N], 0, 26);
		N = 0;
		p = str;
		while (sscanf(p, "%s%n", q, &off) == 1){
			getindex(q[0]);
			p += off;
		}

		qsort(letters, N, sizeof(char), sort_function);
		p = gets(str);
		while (sscanf(p, "%s %s%n", q, w, &off) == 2){
			map[getindex(q[0])][getindex(w[0])] = 1;
			p += off;
		}

		memset(mask, 0, N);
		generate_orders(0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
