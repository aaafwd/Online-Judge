/* @JUDGE_ID: 19899RK 10075 C++ "By Anadan" */ 
// Airlines
// Accepted (0.066 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct City{
	int i;
	char name[32];
	double x, y, z;
}pt[100];
const double Re = 6378.0;
const double pi = 3.141592653589793;
const double coeff = pi / 180.0;

int sort_function(const void *a, const void *b){
	return strcmp(((City *)a)->name, ((City *)b)->name);
}

int main(){
	int set = 0, N, M, Q, i, j, k, map[100][100];
	City c1, c2, *p1, *p2;
	double a, b;

	while (scanf("%d%d%d\n", &N, &M, &Q) == 3 && (N || M || Q)){
		for (i = 0; i < N; ++i){
			scanf("%s%lf%lf\n", pt[i].name, &a, &b);
			a *= coeff; b *= coeff;
			pt[i].x = cos(a);
			pt[i].y = pt[i].x * sin(b);
			pt[i].x *= cos(b);
			pt[i].z = sin(a);
			memset(map[i], -1, sizeof(int) * N);
		}

		qsort(pt, N, sizeof(City), sort_function);
		for (i = 0; i < N; ++i) pt[i].i = i;
		while (M--){
			scanf("%s%s\n", c1.name, c2.name);
			p1 = (City *)bsearch(&c1, pt, N, sizeof(City), sort_function);
			p2 = (City *)bsearch(&c2, pt, N, sizeof(City), sort_function);
			i = p1->i; j = p2->i;
			if (map[i][j] == -1){
				a = pt[i].x * pt[j].x + pt[i].y * pt[j].y + pt[i].z * pt[j].z;
				map[i][j] = (int)floor(acos(a) * Re + 0.5);
			}
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == -1) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == -1) continue;
					if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j]){
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}

		if (set) putchar('\n');
		printf("Case #%d\n", ++set);
		while (Q--){
			scanf("%s%s\n", c1.name, c2.name);
			p1 = (City *)bsearch(&c1, pt, N, sizeof(City), sort_function);
			p2 = (City *)bsearch(&c2, pt, N, sizeof(City), sort_function);
			i = p1->i; j = p2->i;
			if (map[i][j] == -1) puts("no route exists");
			else printf("%d km\n", map[i][j]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
