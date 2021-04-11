/* @JUDGE_ID: 19899RK 10408 C++ "By Anadan" */
// Farey sequences
// Accepted (6.629 seconds using as much as 5228 kbytes)

#include <stdio.h>
#include <stdlib.h>
#define SZ 310000

struct Fraction{
	int x, y;
}pt[SZ];

int sort_function(const void *a, const void *b){
	Fraction *fa = (Fraction *)a, *fb = (Fraction *)b;
	if (fa->x*fb->y < fa->y*fb->x) return -1;
	return 1;
}

int gcd1(int x, int y){
	while(x && y){
		if ((!(x & 1)) && (!(y & 1))) return 0;
		while (!(x & 1)) x >>= 1;
		while (!(y & 1)) y >>= 1;
		if (y > x) y -= x; else x -= y;
	}

	if (x && x != 1) return 0;
	if (y && y != 1) return 0;
	return 1;
}

int main(){
	int n, k, N, i, j;

	while (scanf("%d%d", &n, &k) == 2){
		N = 1;
		pt[0].x = pt[0].y = 1;
		for (i = 1; i <= n; ++i){
			for (j = i + 1; j <= n; ++j){
				if (gcd1(i, j)){
					pt[N].x = i; pt[N].y = j;
					++N;
				}
			}
		}

		qsort(pt, N, sizeof(Fraction), sort_function);

		--k;
		printf("%d/%d\n", pt[k].x, pt[k].y);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
