/* @JUDGE_ID: 19899RK 10369 C++ "By Anadan" */
// Arctic Network
// Accepted (0.550 seconds using as much as 408 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>

int N;
struct Point{
	int x, y;
}pt[500];
char flags[500];

inline int sqr(int x) { return x*x; }

void setnet(int n, int max){
	int i = 0, j = 1, k, vertexes[500];
	vertexes[0] = n;

	flags[n] = 1;
	while (i < j){
		n = vertexes[i++];
		for (k = 0; k < N; ++k){
			if (flags[k] == 0 &&  sqr(pt[n].x - pt[k].x) + sqr(pt[n].y - pt[k].y) <= max){
				vertexes[j++] = k;
				flags[k] = 1;
			}
		}
	}
}

int getnets(int max){
	int i, res = 0;
	memset(flags, 0, N);

	for (i = 0; i < N; ++i){
		if (flags[i] == 0){
			setnet(i, max);
			++res;
		}
	}

	return res;
}

int main(){
	int set, s, i, j, tmp, minimax, minimin;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d", &s, &N);
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);

		minimin = 0;
		minimax = sqr(10001);
		for (i = 0; i < N; i++){
			for (j = i + 1; j < N; j++){
				tmp = sqr(pt[j].x - pt[i].x) + sqr(pt[j].y - pt[i].y);
				if (tmp >= minimax) continue;
				if (tmp <= minimin) continue;
				if (getnets(tmp) <= s) minimax = tmp;
				else minimin = tmp;
			}
		}

		printf("%.2lf\n", sqrt(minimax));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
