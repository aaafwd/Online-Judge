/* @JUDGE_ID: 19899RK 643 C++ "By Anadan" */ 
// Bulk Mailing
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 500
#define ER 100

int sort_function(const void *a, const void *b){
	if (*(int *)a < *(int *)b) return -1;
	return 1;
}

int main(){
	int N, E, i, j, k, l, bundles;
	int zip[SZ];
	char str[SZ], err[ER][21];

	N = E = bundles = 0;
	while (scanf("%s\n", str) == 1){
		i = 0;
		if (strlen(str) == 5){
			for (i = 0; i < 5; ++i) if (str[i] < '0' || str[i] > '9') break;
		}

		if (i == 5) sscanf(str, "%d", zip + N);
		if (i < 5 || !zip[N]){
			for (i = 0; i < E; ++i) if (strcmp(err[i], str) == 0) break;
			if (i == E) strcpy(err[E++], str);
		}else ++N;
	}

	qsort(zip, N, sizeof(int), sort_function);

	memset(str, 0, N);
	printf("ZIP         LETTERS     BUNDLES\n\n");

	// 5-digit bundles
	for (i = 0; i < N; ++i){
		for (j = i + 1; j < N && zip[j] == zip[i]; ++j);
		j -= i;
		if (j < 10){
			i += j - 1;
			continue;
		}

		k = j / 15;
		while (j > 15 * k){
			++k;
			if (k > j / 10){
				--k;
				break;
			}
		}

		l = 15 * k;
		if (l > j) l = j;

		printf("%.5ld %10d %11d\n", zip[i], l, k);
		bundles += k;

		for (k = i; l--; ++k) str[k] = 1;
		i += j - 1;
	}
	putchar('\n');

	// 3-digit bundles
	for (i = 0; i < N; ++i){
		if (str[i]) continue;
		k = int(zip[i] / 100);
		for (l = 1, j = i + 1; j < N; ++j){
			if (str[j]) continue;
			if (zip[j] / 100 == k) ++l; else break;
		}

		if (l < 10){
			i += l - 1;
			continue;
		}
		printf("%.3dxx ", k);

		k = l / 15;
		while (l > 15 * k){
			++k;
			if (k > l / 10){
				--k;
				break;
			}
		}

		j = 15 * k;
		if (j > l) j = l;

		printf("%10d %11d\n", j, k);
		bundles += k;

		for (k = i; j; ++k){
			if (str[k]) continue;
			str[k] = 1;
			--j;
		}

		i = k - 1;
	}
	putchar('\n');

	// first class letters
	for (i = 0; i < N; ++i){
		if (str[i]) continue;
		for (l = 1, j = i + 1; j < N && zip[j] == zip[i]; ++j, ++l);
		printf("%.5ld %10d %11d\n", zip[i], l, 0);
		i += l - 1;
	}

	printf("\nTOTALS%10d %11d\n\nINVALID ZIP CODES\n", N, bundles);
	for (i = 0; i < E; ++i) printf("%s\n", err[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
