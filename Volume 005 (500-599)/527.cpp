/* @JUDGE_ID: 19899RK 527 C++ "By Anadan" */ 
// The partition of a cake
// Accepted (0.076 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point{
	double x, y;
};

struct Stick{
	int x1, y1, x2, y2;
	int operator == (Stick &st) { return (x1 == st.x1 && x2 == st.x2 && y1 == st.y1 && y2 == st.y2); }
}pt[8];

int sort_function(const void *a, const void *b){
	if (((Point *)a)->x < ((Point *)b)->x) return -1;
	if (((Point *)a)->x > ((Point *)b)->x) return 1;
	if (((Point *)a)->y < ((Point *)b)->y) return -1;
	return 1;
}

int main(){
	int set, i, j, M, N, parts, det, it1, it2;
	Point ppt[80];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);

		parts = 1;
		for (i = 0; i < N; ++i){
			scanf("%d%d%d%d\n", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
			if (pt[i].x1 > pt[i].x2 || (pt[i].x1 == pt[i].x2 && pt[i].y1 > pt[i].y2)){
				pt[i].x1 ^= pt[i].x2 ^= pt[i].x1 ^= pt[i].x2;
				pt[i].y1 ^= pt[i].y2 ^= pt[i].y1 ^= pt[i].y2;
			}

			for (j = 0; j < i; ++j){
				if (pt[i] == pt[j]) break;
			}
			if (j < i) continue;

			for (M = j = 0; j < i; ++j){
				det = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
				it1 = (pt[j].x1 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[j].y1 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
				it2 = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[i].y1) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[i].x1);
				if (det == 0) continue;
				if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
				if (it1 <= 0 || it2 <= 0 || it1 >= det || it2 >= det) continue;
				ppt[M].x = pt[i].x1 + double(it1) * (pt[i].x2 - pt[i].x1) / double(det);
				ppt[M].y = pt[i].y1 + double(it1) * (pt[i].y2 - pt[i].y1) / double(det);
				++M;
			}

			qsort(ppt, M, sizeof(Point), sort_function);
			++parts;
			if (M) ++parts;
			for (j = 1; j < M; ++j){
				if (fabs(ppt[j].x - ppt[j - 1].x) > 0.01 || fabs(ppt[j].y - ppt[j - 1].y) > 0.01) ++parts;
			}
		}

		printf("%d\n", parts);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
