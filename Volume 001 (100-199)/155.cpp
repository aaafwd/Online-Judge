/* @JUDGE_ID: 19899RK 155 C++ "By Anadan" */
// All Squares
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

int x, y;

int func(int xc, int yc, int k){
	int res = 0;
	while (k){
		if (x > xc) x = 2*xc - x;
		if (y > yc) y = 2*yc - y;
		if (x >= xc - k && y >= yc - k) ++res;
		xc -= k; yc -= k;
		k >>= 1;
	}

	return res;
}

int main(){
	int k;

	while (scanf("%d%d%d\n", &k, &x, &y) == 3){
		if (k == 0 && x == 0 && y == 0) break;
		printf("%3d\n", func(1024, 1024, k));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
