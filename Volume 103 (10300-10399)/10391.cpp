/* @JUDGE_ID: 19899RK 10391 C++ "By Anadan" */
// Compound Words
// Accepted (0.229 seconds using as much as 2728 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 120000u

int N;
char dict[SZ][20];

int find(char *str, int n){
	int i = 0, j = N - 1, k, r;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (k == n){
			if (j == i + 2) break;
			--k;
			if (k == i) k += 2;
		}

		r = strcmp(str, dict[k]);
		if (r == 0) return k;
		if (r < 0) j = k;
		else i = k;
	}

	if (i != n && strcmp(str, dict[i]) == 0) return i;
	if (j != n && j != i && strcmp(str, dict[j]) == 0) return j;

	return -1;
}

int main(){
	int i, j, k;
	char *p, c;

	N = 0;
	while (N < SZ && scanf("%s", dict[N]) == 1) ++N;

	for (i = 0; i < N; ++i){
		for (p = dict[i] + 1; *p; ++p){
			c = *p;
			*p = 0;
			j = find(dict[i], i);
			if (j != -1){
				*p = c;
				k = find(p, i);
				if (k != -1) break;
			}else *p = c;
		}

		if (*p) printf("%s\n", dict[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
