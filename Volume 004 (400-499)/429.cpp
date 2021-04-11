/* @JUDGE_ID: 19899RK 429 C++ "By Anadan" */
// Word Transformation
// Accepted (1.240 seconds using as much as 396 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>

int N;
char dict[201][11];

int isstep(int i, int j){
	char *p = dict[i], *q = dict[j];
	while (*p && *q && *p == *q) p++, q++;
	if (*p++ == 0 || *q++ == 0) return 0;
	while (*p && *q && *p == *q) p++, q++;
	if (*p == 0 && *q == 0) return 1;
	return 0;
}

int transform(int k1, int k2){
	int i, j, step, res[200];

	memset(res, 0, N * sizeof(int));
	res[k1] = 1;
	for (step = 1; res[k2] == 0; step++){
		for (i = 0; i < N; i++){
			if (res[i] != step) continue;
			for (j = 0; j < N; j++){
				if (res[j]) continue;
				if (isstep(i, j)) res[j] = step + 1;
			}
		}
	}
	return res[k2] - 1;
}

int main(){
	int i, k1, k2;
	long set;
	char str[40], s1[11], s2[11], *p;
	scanf("%ld\n\n", &set);

	while (set--){
		for (N = 0; ;N++){
			scanf("%s\n", dict[N]);
			if (dict[N][0] == '*') break;
		}

		while (gets(str)){
			if (str[0] == 0) break;
			sscanf(str, "%s %s", s1, s2);
			if (!strcmp(s1, s2)){
				printf("%s %s 0\n", s1, s2);
				continue;
			}
			for (i = 0; i < N; i++){
				if (!strcmp(dict[i], s1)) k1 = i;
				if (!strcmp(dict[i], s2)) k2 = i;
			}
			printf("%s %s %d\n", s1, s2, transform(k1, k2));
		}

		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
