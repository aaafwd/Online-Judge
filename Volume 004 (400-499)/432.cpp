/* @JUDGE_ID: 19899RK 432 C++ "By Anadan" */ 
// Modern Art
// Accepted (0.100 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, p, q, x, y, u, cx, cy;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d%d%d\n", &p, &q, &x, &y);
		printf("(%d,%d)(0,0)\n", x, y);
		u = 0;
		cx = x >> p;
		cy = y >> p;
		while (p--){
			printf("(%d,0)(%d,0)\n", u, cx + cx);
			printf("(%d,0)(%d,%d)\n", cx + cx, cx, cy);
			printf("(%d,%d)(%d,%d)\n", cx, cy, cx + cx + cx, cy);
			printf("(%d,%d)(%d,0)\n", cx + cx + cx, cy, cx + cx);
			u = cx + cx;
			cx <<= 1;
			cy <<= 1;
		}

		cx = x >> 2;
		cy = y >> 2;
		while (--q > 0){
			printf("(%d,0)(%d,0)\n", u, u + cx + cx);
			printf("(%d,0)(%d,%d)\n", u + cx + cx, u + cx, cy);
			printf("(%d,%d)(%d,%d)\n", u + cx, cy, u + cx + cx + cx, cy);
			printf("(%d,%d)(%d,0)\n", u + cx + cx + cx, cy, u + cx + cx);
			u += cx + cx;
			cx >>= 1;
			cy >>= 1;
		}

		printf("(%d,0)(%d,0)\n", u, x + x);
		printf("(%d,0)(%d,%d)\n\n", x + x, x, y);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
