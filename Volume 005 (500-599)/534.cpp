/* @JUDGE_ID: 19899RK 534 C++ "By Anadan" */
// Frogger
// Accepted (0.010 seconds with low memory spent)

#include <math.h>
#include <stdio.h>
#include <string.h>

int N;
struct Point{
	int x, y;
}pt[200];
unsigned char flags[200], w1[200], w2[200];

inline int sqr(int x) { return x*x; }

int reachable(int max){
	int i, j, n1 = 1, n2;

	w1[0] = 0;
	memset(flags, 0, N);
	while (n1){
		for (i = n2 = 0; i < n1; i++){
			for (j = 1; j < N; j++){
				if (flags[j]) continue;
				if (sqr(pt[w1[i]].x - pt[j].x) + sqr(pt[w1[i]].y - pt[j].y) <= max){
					if (j == 1) return 1;
					w2[n2++] = j;
					flags[j] = 1;
				}
			}
		}
		n1 = n2;
		memcpy(w1, w2, n2);
	}

	return 0;
}

int main(){
	int i, j, tmp, minimax, minimin, set = 0;

	while (scanf("%d\n", &N) > 0){
		if (N == 0) break;
		for (i = 0; i < N; i++) scanf("%d %d\n", &pt[i].x, &pt[i].y);

		minimin = 0;
		minimax = sqr(pt[1].x - pt[0].x) + sqr(pt[1].y - pt[0].y);
		for (i = 0; i < N; i++){
			for (j = i + 1; j < N; j++){
				tmp = sqr(pt[j].x - pt[i].x) + sqr(pt[j].y - pt[i].y);
				if (tmp >= minimax) continue;
				if (tmp <= minimin) continue;
				if (reachable(tmp)) minimax = tmp;
				else minimin = tmp;
			}
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++set, sqrt(minimax));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
