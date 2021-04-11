/* @JUDGE_ID: 19899RK 242 C++ "By Anadan" */ 
// Stamps and Envelope Size
// Accepted (0.752 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <stdlib.h>

struct StampSet{
	int N, stamps[10];
}pt[10];
int S;

int sort_function(const void *a, const void *b){
	StampSet *sa = (StampSet *)a, *sb = (StampSet *)b;
	if (sa->N < sb->N) return -1;
	if (sa->N > sb->N) return 1;
	if (sa->stamps[sa->N - 1] < sb->stamps[sb->N - 1]) return -1;
	return 1;
}

int getmaxnogap(int n){
	int cur, i, j, k;
	char mins[1001];

	mins[0] = 0;
	for (cur = 1 ;; ++cur){
		mins[cur] = 127;

		for (i = 0; i < pt[n].N; ++i){
			for (k = 1, j = cur - pt[n].stamps[i]; j >= 0 && k <= S; j -= pt[n].stamps[i], ++k){
				if (mins[cur] > mins[j] + k && mins[j] + k <= S){
					mins[cur] = mins[j] + k;
				}
			}
		}

		if (mins[cur] == 127) break;
	}

	return cur - 1;
}

int main(){
	int N, i, j, max, tmp;

	while (scanf("%d\n", &S) == 1 && S){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			scanf("%d", &pt[i].N);
			for (j = 0; j < pt[i].N; ++j){
				scanf("%d", &pt[i].stamps[j]);
			}
		}

		qsort(pt, N, sizeof(StampSet), sort_function);

		max = -1;
		for (i = 0; i < N; ++i){
			tmp = getmaxnogap(i);
			if (max < tmp){
				max = tmp;
				j = i;
			}
		}

		printf("max coverage = %3d :", max);
		for (i = 0; i < pt[j].N; ++i) printf("%3d", pt[j].stamps[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
