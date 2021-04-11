/* @JUDGE_ID: 19899RK 10416 C++ "By Anadan" */
// Folding My T-Shirt
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

struct Point{
	int x, y;
}pt[200];

inline int sqr(int x) { return x * x; }

int main(){
	int set, N, N2, i, j, a, b;
	int x, y, tmp;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		scanf("%d%d", &pt[0].x, &pt[0].y);

		for (j = i = 1; i < N; ++i){
			scanf("%d%d", &x, &y);
			pt[j].x = pt[j - 1].x + x;
			pt[j].y = pt[j - 1].y + y;
			pt[j - 1].x <<= 1; pt[j - 1].y <<= 1;
			pt[++j].x = x; pt[j++].y = y;
		}
		pt[j].x = pt[j - 1].x + pt[0].x / 2;
		pt[j].y = pt[j - 1].y + pt[0].y / 2;
		pt[j - 1].x <<= 1; pt[j - 1].y <<= 1;

		N2 =  N << 1;
		for (i = 0; i < N; ++i){
			j = i + N;
			a = (i + N2 - 1) % N2; b = (i + 1) % N2;
			x = pt[j].x - pt[i].x; y = pt[j].y - pt[i].y;
			while (a != j && b != j){
				tmp = x * (pt[a].x - pt[b].x) + y * (pt[a].y - pt[b].y);
				if (tmp) break;
				tmp  = sqr(pt[a].x - pt[i].x) + sqr(pt[a].y - pt[i].y) - sqr(pt[b].x - pt[i].x) - sqr(pt[b].y - pt[i].y);
				if (tmp) break;
				a = (a + N2 - 1) % N2; b = (b + 1) % N2;
			}

			if (a == j && b == j) break;
		}

		if (i < N) printf("Yes\n"); else printf("No\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
