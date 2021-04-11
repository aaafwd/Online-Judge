/* @JUDGE_ID: 19899RK 10321 C++ "By Anadan" */ 
// Polygon intersection
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Point{
	double x, y;
}pt[200];
int x[100], y[100], N, index, ins[100];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->x < ((Point *)b)->x) return -1;
	if (((Point *)a)->x > ((Point *)b)->x) return 1;
	if (((Point *)a)->y < ((Point *)b)->y) return -1;
	return 1;
}

void addpoints(int x1, int y1, int x2, int y2){
	int i, j, det, it1, it2, inside = 0;

	for (i = 0; i < N; ++i){
		j = ((i == N - 1) ? (0) : (i + 1));

		det = (x2 - x1) * (y[i] - y[j]) - (x[i] - x[j]) * (y2 - y1);
		it1 = (x[i] - x1) * (y[i] - y[j]) - (x[i] - x[j]) * (y[i] - y1);
		it2 = (x2 - x1) * (y[i] - y1) - (x[i] - x1) * (y2 - y1);

		if (it1 == 0) inside = -2;
		else if (inside == 0) inside = ((it1 < 0) ? (-1) : (1));
		else if (inside == -1 && it1 > 0) inside = -2;
		else if (inside == 1 && it1 < 0) inside = -2;

		if (it2 == 0) ins[i] = -2;
		else if (ins[i] == 0) ins[i] = ((it2 < 0) ? (-1) : (1));
		else if (ins[i] == -1 && it2 > 0) ins[i] = -2;
		else if (ins[i] == 1 && it2 < 0) ins[i] = -2;

		if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
		if (det == 0 || it1 <= 0 || it2 <= 0) continue;
		if (it1 > det || it2 > det) continue;

		pt[index].x = x1 + double(x2 - x1) * double (it1) / double(det);
		pt[index].y = y1 + double(y2 - y1) * double (it1) / double(det);
		++index;
	}

	if (inside == 1 || inside == -1){
		pt[index].x = x1;
		pt[index].y = y1;
		++index;
	}
}

int main(){
	int M, i, x0, y0, x1, y1, x2, y2;

	while (scanf("%d\n", &N) == 1 && N > 2){
		for (i = 0; i < N; ++i){
			scanf("%d%d\n", x + i, y + i);
			ins[i] = 0;
		}

		scanf("%d\n%d%d\n", &M, &x0, &y0);
		x1 = x0; y1 = y0;
		index = 0;
		for (i = 1; i < M; ++i){
			scanf("%d%d\n", &x2, &y2);
			addpoints(x1, y1, x2, y2);
			x1 = x2; y1 = y2;
		}

		addpoints(x1, y1, x0, y0);

		for (i = 0; i < N; ++i){
			if (ins[i] == 1 || ins[i] == -1){
				pt[index].x = x[i];
				pt[index].y = y[i];
				++index;
			}
		}

		qsort(pt, index, sizeof(Point), sort_function);

		printf("%d\n", index);
		for (i = 0; i < index; ++i){
			printf("%.2lf %.2lf\n", pt[i].x, pt[i].y);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
