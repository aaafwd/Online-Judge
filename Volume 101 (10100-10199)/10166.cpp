/* @JUDGE_ID: 19899RK 10166 C++ "By Anadan" */ 
// Travel
// Accepted (1.943 seconds using as much as 1000 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, T;
struct Train{
	int *time;
}pt[100];
char names[100][32];

int sort_function(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

void getarrival(int mint, int maxt, int src, int dst){
	int i, j, k, m, dep, depart[100][1441];
	char mask[100];

	memset(depart, -1, sizeof(depart));
	for (i = mint; i <= maxt; ++i) depart[src][i] = i;

	memset(mask, 0, N);
	mask[src] = 1;

	while (1){
		for (i = 0; i < N; ++i) if (mask[i]) break;
		if (i == N) break;
		mask[i] = 0;
		for (k = 0; k < T; ++k){
			if (pt[k].time[i] == -1) continue;
			if (depart[i][pt[k].time[i]] == -1) continue;

			for (m = 0; m < N; ++m){
				if (pt[k].time[m] == -1 || m == i) continue;
				if (pt[k].time[m] < pt[k].time[i]) continue;
				if (depart[m][pt[k].time[m]] < depart[i][pt[k].time[i]]){
					depart[m][pt[k].time[m]] = depart[i][pt[k].time[i]];
					for (j = pt[k].time[m] + 1; j <= maxt; ++j){
						if (depart[m][j] < depart[m][pt[k].time[m]]){
							depart[m][j] = depart[m][pt[k].time[m]];
						}else break;
					}
					mask[m] = 1;
				}
			}
		}
	}

	for (i = mint; i <= maxt; ++i) if (depart[dst][i] != -1) break;

	if (i > maxt) printf("No connection\n");
	else printf("%.2d%.2d %.2d%.2d\n", depart[dst][i] / 60, depart[dst][i] % 60, i / 60, i % 60);
}

int main(){
	int i, j, k, m, time[100], hh, mm, max;
	char str[80], *p;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%s\n", names[i]);
		qsort(names, N, sizeof(names[0]), sort_function);

		max = 0;
		scanf("%d\n", &T);
		for (i = 0; i < T; ++i){
			scanf("%d\n", &k);
			memset(time, -1, sizeof(time));
			for (j = 0; j < k; ++j){
				scanf("%2d%2d %s\n", &hh, &mm, str);
				p = (char *)bsearch(str, names, N, sizeof(names[0]), sort_function);
				m = int(p - (char *)names) / sizeof(names[0]);
				time[m] = hh * 60 + mm;
				if (max < time[m]) max = time[m];
			}

			pt[i].time = (int *)memcpy((int *)malloc(sizeof(int) * N), time, sizeof(int) * N);
		}

		scanf("%2d%2d%s", &hh, &mm, str);
		p = (char *)bsearch(str, names, N, sizeof(names[0]), sort_function);
		i = int(p - (char *)names) / sizeof(names[0]);
		scanf("%s\n", str);
		p = (char *)bsearch(str, names, N, sizeof(names[0]), sort_function);
		j = int(p - (char *)names) / sizeof(names[0]);

		getarrival(hh * 60 + mm, max, i, j);

		for (i = 0; i < T; ++i) free(pt[i].time);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
