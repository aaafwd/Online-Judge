/* @JUDGE_ID: 19899RK 634 C++ "By Anadan" */ 
// Polygon
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Point{
	int x, y;
}pt[1000];

int main(){
	int N, i, j, x, y, count;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d\n", &pt[i].x, &pt[i].y);
		scanf("%d%d\n", &x, &y);
		count = 0;
		for (i = 0; i < N; ++i){
			if (i == N - 1) j = 0; else j = i + 1;
			if (pt[i].x == pt[j].x || pt[i].y < y) continue;
			if (pt[i].x < pt[j].x){
				if (pt[i].x < x && x < pt[j].x) count ^= 1;
			}else{
				if (pt[j].x < x && x < pt[i].x) count ^= 1;
			}
		}

		if (count) printf("T\n"); else printf("F\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
