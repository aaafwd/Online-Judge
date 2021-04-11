/* @JUDGE_ID: 19899RK 106 C++ "By Anadan" */
// Fermat vs. Pythagoras
// Accepted (0.918 seconds using as much as 12096 kbytes)

#include <stdio.h>
#define MAX 1000000

int triples[MAX + 1];
int minz[MAX + 1];
int secn[MAX + 1];

int main(){
	int a, b, x, y, z, x0, y0, z0;

	for (a = 1; a <= 1000; ++a){
		for (b = a + 1; b <= 1000; ++b){
			z0 = z = b*b + a*a;
			if (z > MAX) break;
			x0 = x = b*b - a*a;
			y0 = y = 2*a*b;

			while (x && y) if (x > y) x %= y; else y %= x;
			if (x != 1 && y != 1) continue;

			x = x0; y = y0;
			++triples[z];

			do{
				if (!minz[x] || minz[x] > z) minz[x] = z;
				if (!minz[y] || minz[y] > z) minz[y] = z;
				if (!minz[z] || minz[z] > z) minz[z] = z;
				x += x0; y += y0; z += z0;
			}while (z <= MAX);
		}
	}

	for (a = 1; a <= MAX; ++a){
		triples[a] += triples[a - 1];
		++secn[minz[a]];
	}

	secn[0] = 0;
	for (a = 1; a <= MAX; ++a) secn[a] += secn[a - 1];

	while (scanf("%d\n", &a) == 1){
		printf("%d %d\n", triples[a], a - secn[a]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
