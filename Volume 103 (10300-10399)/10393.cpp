/* @JUDGE_ID: 19899RK 10393 C++ "By Anadan" */
// The One-Handed Typist
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char letters[] = "qazwsxedcrfvtgb  yhnujmik,ol.p;/";
const char fingers[] = "11122233344444456777777888999000";
char notuse[10];

char dict[1000][51];

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int cantype(int n){
	char *p;
	const char *q;

	for (p = dict[n]; *p; ++p){
		q = strchr(letters, *p);
		if (q == NULL) return 0;
		q = fingers + int(q - letters);
		if (notuse[*q - '0'] == 1) return 0;
	}

	return 1;
}

int main(){
	int F, N, i, max, len;
	int stack[1000];
	char str[1024];

	while (scanf("%d%d", &F, &N) == 2){
		memset(notuse, 0, 10);
		while (F--){
			scanf("%d", &i);
			if (i == 10) i = 0;
			notuse[i] = 1;
		}

		for (F = 0; F < N; ++F){
			scanf("%s\n", dict[F]);
		}

		qsort(dict, N, sizeof(dict[0]), sort_function);

		for (i = F = 0; F < N; ++F){
			if (cantype(F)){
				max = strlen(dict[F]);
				stack[0] = F;
				i = 1;
				break;
			}
		}

		for (++F; F < N; ++F){
			len = strlen(dict[F]);
			if (len < max) continue;
			if (cantype(F)){
				if (len == max){
					if (strcmp(dict[F], dict[F - 1])){
						stack[i++] = F;
					}
				}else{
					max = len;
					stack[0] = F;
					i = 1;
				}
			}
		}

		printf("%d\n", i);
		for (F = 0; F < i; ++F){
			printf("%s\n", dict[stack[F]]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
