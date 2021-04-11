/* @JUDGE_ID: 19899RK 216 C++ "By Anadan" */
// Getting in Line
// Accepted (0.037 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>

int N, best[8], curr[8];
struct Point{
	int x, y;
}pt[8];
double min, map[8][8];
char mask[8];

void generate(int n, double len){
	int i;

	if (len >= min) return;
	if (n == 0){
		for (i = 0; i < N; ++i){
			curr[0] = i;
			mask[i] = 1;
			generate(1, 0.0);
			mask[i] = 0;
		}

		return;
	}

	if (n == N){
		min = len;
		for (i = 0; i < N; ++i) best[i] = curr[i];
		return;
	}

	for (i = 0; i < N; ++i){
		if (mask[i]) continue;
		mask[i] = 1;
		curr[n] = i;
		generate(n + 1, len + map[curr[n - 1]][i]);
		mask[i] = 0;
	}
}

inline int sqr(int x) { return x * x; }

int main(){
	int i, j, set = 0;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d\n", &pt[i].x, &pt[i].y);
		for (i = 0; i < N; ++i){
			for (j = i + 1; j < N; ++j){
				map[i][j] = map[j][i] = sqrt(sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y)) + 16.0;
			}
		}

		min = 20000.0;
		memset(mask, 0, N);
		generate(0, 0.0);

		printf("**********************************************************\n");
		printf("Network #%d\n", ++set);
		for (i = 1; i < N; ++i){
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", pt[best[i - 1]].x, pt[best[i - 1]].y, pt[best[i]].x, pt[best[i]].y, map[best[i - 1]][best[i]]);
		}
		printf("Number of feet of cable required is %.2lf.\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
