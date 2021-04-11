/* @JUDGE_ID: 19899RK 10436 C++ "By Anadan" */ 
// Cheapest way
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 20

int N, e[SZ][SZ];
struct City{
	char name[21];
	int tax, i;
}pt[SZ];

int sort_function(const void *a, const void *b){
	return strcmp(((City *)a)->name, ((City *)b)->name);
}

void outroute(int i, int j){
	while (e[i][j] != -1){
		outroute(i, e[i][j]);
		i = e[i][j];
	}

	printf(" %s", pt[j].name);
}

int main(){
	int set, nmap, nquery, i, j, k, map[SZ][SZ];
	double taka;
	City s1, s2, *p1, *p2;

	nmap = 0;
	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			scanf("%s%d\n", pt[i].name, &pt[i].tax);
			for (j = 0; j < N; ++j) map[i][j] = e[i][j] = -1;
		}
		qsort(pt, N, sizeof(City), sort_function);
		for (i = 0; i < N; ++i) pt[i].i = i;

		scanf("%d\n", &k);
		while (k--){
			scanf("%s%s%d\n", s1.name, s2.name, &i);
			p1 = (City *)bsearch(&s1, pt, N, sizeof(City), sort_function);
			p2 = (City *)bsearch(&s2, pt, N, sizeof(City), sort_function);
			map[p1->i][p2->i] = map[p2->i][p1->i] = i << 1;
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j] + pt[k].tax){
						map[i][j] = map[i][k] + map[k][j] + pt[k].tax;
						e[i][j] = k;
					}
				}
			}
		}

		printf("Map #%d\n", ++nmap);
		scanf("%d\n", &k);
		nquery = 0;
		while (k--){
			scanf("%s%s%d\n", s1.name, s2.name, &i);
			p1 = (City *)bsearch(&s1, pt, N, sizeof(City), sort_function);
			p2 = (City *)bsearch(&s2, pt, N, sizeof(City), sort_function);

			printf("Query #%d\n%s", ++nquery, p1->name);
			outroute(p1->i, p2->i);
			taka = (p1->tax + p2->tax + map[p1->i][p2->i]) * 1.1 / double(i);
			printf("\nEach passenger has to pay : %.2lf taka\n", taka);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
