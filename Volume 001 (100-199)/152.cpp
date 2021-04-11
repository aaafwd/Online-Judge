/* @JUDGE_ID: 19899RK 152 C++ "By Anadan" */
// Tree's a Crowd
// Accepted (2.082 seconds using as much as 440 kbytes)

#include <stdio.h>

struct Point{
	int x, y, z;
}pt[5000];

const int square[] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };

inline int sqr(int x) { return x * x; }

int main(){
	int N = 0, res[10], i, j, min, tmp;
	Point p;

	while (scanf("%d%d%d\n", &p.x, &p.y, &p.z) == 3){
		if (p.x == 0 && p.y == 0 && p.z == 0) break;
		pt[N++] = p;
	}

	for (i = 0; i < 10; ++i) res[i] = 0;
	for (i = 0; i < N; ++i){
		min = 100;
		for (j = 0; j < N; ++j){
			if (i == j) continue;
			tmp = sqr(pt[j].x - pt[i].x) + sqr(pt[j].y - pt[i].y) + sqr(pt[j].z - pt[i].z);
			if (min > tmp) min = tmp;
		}

		if (min < 100){
			for(j = 9; min < square[j]; --j);
			++res[j];
		}
	}

	for (i = 0; i < 10; ++i) printf("%4d", res[i]);
	printf("\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
