/* @JUDGE_ID: 19899RK 10348 C++ "By Anadan" */
// Submarines
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

struct Submarine{
	int x1, y1, x2, y2;
}pt[100];
struct Island{
	int N, x[20], y[20];
}is[50];
int S, I;

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int det = (x2 - x1) * (y3 - y4) - (y2 - y1) * (x3 - x4);
	int it1 = (x3 - x1) * (y3 - y4) - (y3 - y1) * (x3 - x4);
	int it2 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if (det == 0) return 0;
	if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
	return (0 < it1 && it1 < det && 0 < it2 && it2 < det);
}

int isinpolygon(int n, int x, int y){
	int i, j, x1, y1, x2, y2, a, b, count = 0;

	for (i = 0; i < is[n].N; ++i){
		j = ((i == is[n].N - 1) ? 0 : i + 1);
		if (is[n].y[i] < is[n].y[j]){
			x1 = is[n].x[i];
			y1 = is[n].y[i];
			x2 = is[n].x[j];
			y2 = is[n].y[j];
		}else{
			x2 = is[n].x[i];
			y2 = is[n].y[i];
			x1 = is[n].x[j];
			y1 = is[n].y[j];
		}

		if (y1 == y2) continue;
		a = y - y1;
		b = y2 - y1;

		if (b < 0) { a = -a; b = -b; }
		if (a < 0 || a >= b) continue;

		a = b * (x1 - x) + a * (x2 - x1);
		if (a > 0) ++count;
	}

	return (count & 1);
}

int main(){
	int i, j, k, m;

	scanf("%d", &S);
	for (i = 0; i < S; ++i) scanf("%d%d%d%d", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);

	scanf("%d", &I);
	for (i = 0; i < I; ++i){
		scanf("%d", &is[i].N);
		for (j = 0; j < is[i].N; ++j) scanf("%d%d", &is[i].x[j], &is[i].y[j]);
	}

	for (i = 0; i < S; ++i){
		printf("Submarine %d is ", i + 1);
		for (j = 0; j < I; ++j){
			for (k = 0; k < is[j].N; ++k){
				m = ((k == is[j].N - 1) ? 0 : k + 1);
				if (intersect(is[j].x[k], is[j].y[k], is[j].x[m], is[j].y[m], pt[i].x1, pt[i].y1, pt[i].x2, pt[i].y2)) break;
			}

			if (k < is[j].N) break;
		}

		if (j < I) puts("partially on land.");
		else{
			for (j = 0; j < I; ++j){
				if (isinpolygon(j, pt[i].x1, pt[i].y1)) break;
			}

			if (j < I) puts("completely on land.");
			else puts("still in water.");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
