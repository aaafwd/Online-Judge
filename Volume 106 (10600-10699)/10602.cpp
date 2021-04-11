/* @JUDGE_ID: 19899RK 10602 C++ "By Anadan" */
// Editor Nottobad
// Accepted (0.021 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, res[128], sp, totres;
char words[128][128], mask[128];

int getmaxsymb(char * s, char * p){
	int res = 0;
	while (*s && *p && *s++ == *p++) ++res;
	return res;
}

void setnext(){
	int i, j = -1, max, tmp;

	for (i = 1; i < N; ++i){
		if (mask[i]) continue;
		tmp = getmaxsymb(words[res[sp - 1]], words[i]);
		if (j == -1 || max < tmp){
			j = i;
			max = tmp;
		}
	}

	mask[j] = 1;
	res[sp++] = j;
	totres += strlen(words[j]) - max;
}

int main(){
	int set, i;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		for (i = 0; i < N; ++i) scanf("%s", words[i]);

		sp = 0;
		memset(mask, 0, N);
		mask[0] = 1;
		res[sp++] = 0;
		totres = strlen(words[0]);

		while (sp != N) setnext();

		printf("%d\n", totres);
		for (i = 0; i < N; ++i) puts(words[res[i]]);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
