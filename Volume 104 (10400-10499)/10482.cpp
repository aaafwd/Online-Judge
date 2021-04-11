/* @JUDGE_ID: 19899RK 10482 C++ "By Anadan" */ 
// The Candyman Can
// Accepted (0.412 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char taken[32];
int N, candy[32], mindiff, totsum, currsum;

int sort_function(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

inline int max(int a, int b, int c){
	if (a < b) a = b;
	if (a < c) a = c;
	return a;
}

inline int min(int a, int b, int c){
	if (a > b) a = b;
	if (a > c) a = c;
	return a;
}

void makediff(){
	int i, j;
	char mask[641];

	memset(mask, 0, sizeof(mask));
	mask[0] = 1;
	for (i = 0; i < N; ++i){
		if (taken[i]) continue;
		for (j = 640 - candy[i]; j >= 0; --j){
			if (mask[j]) mask[j + candy[i]] = 1;
		}
	}

	for (i = 0; i < 641; ++i){
		if (mask[i]){
			j = max(currsum, i, totsum - currsum - i) - min(currsum, i, totsum - currsum - i);
			if (mindiff > j) mindiff = j;
		}
	}
}

void generate(int sum){
	int i, j;

	if (sum == 0){
		makediff();
		return;
	}

	for (i = 0; i < N; ++i){
		if (taken[i]) continue;
		if (candy[i] > sum) break;
		taken[i] = 1;
		generate(sum - candy[i]);
		taken[i] = 0;

		j = (totsum - currsum) / 2;
		j = max(currsum, j, totsum - currsum - j) - min(currsum, j, totsum - currsum - j);
		if (mindiff <= j) break;

		while (i < N - 1 && candy[i] == candy[i + 1]) ++i;
	}
}

int main(){
	int set, count = 0, i, j, k;
	char mask[641];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		memset(mask, 0, sizeof(mask));
		mask[0] = 1;
		totsum = 0;
		for (i = 0; i < N; ++i){
			scanf("%d", candy + i);
			totsum += candy[i];
			for (j = 640 - candy[i]; j >= 0; --j){
				if (mask[j]) mask[j + candy[i]] = 1;
			}
		}

		qsort(candy, N, sizeof(int), sort_function);

		mindiff = 1000;
		for (k = 0; k < 641; ++k){
			i = totsum / 3 + k;
			if (i < 641 && mask[i]){
				j = (totsum - i) / 2;
				j = max(i, j, totsum - i - j) - min(i, j, totsum - i - j);
				if (mindiff <= j) continue;
				memset(taken, 0, sizeof(taken));
				currsum = i;
				generate(i);
			}

			i = totsum / 3 - k;
			if (i >= 0 && mask[i]){
				j = (totsum - i) / 2;
				j = max(i, j, totsum - i - j) - min(i, j, totsum - i - j);
				if (mindiff <= j) continue;
				memset(taken, 0, sizeof(taken));
				currsum = i;
				generate(i);
			}
		}

		printf("Case %d: %d\n", ++count, mindiff);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
