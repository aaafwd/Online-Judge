/* @JUDGE_ID: 19899RK 833 C++ "By Anadan" */
// Water Falls
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct Segs{
	int x1, y1, x2, y2;
}pt[1000];

int sort_function(const void *a, const void *b){
	if (((Segs *)a)->x1 < ((Segs *)b)->x1) return -1;
	return 1;
}

int main(){
	int set, i, j, k, x, y, N, M;
	double miny, tmp;

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			scanf("%d%d%d%d", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
			if (pt[i].x1 > pt[i].x2){
				pt[i].x1 ^= pt[i].x2 ^= pt[i].x1 ^= pt[i].x2;
				pt[i].y1 ^= pt[i].y2 ^= pt[i].y1 ^= pt[i].y2;
			}
		}

		qsort(pt, N, sizeof(Segs), sort_function);

		scanf("%d\n", &M);
		for (i = 0; i < M; ++i){
			scanf("%d%d\n", &x, &y);
			while (1){
				miny = -1.0;
				for (j = 0; j < N; ++j){
					if (x < pt[j].x1) break;
					if (x < pt[j].x2){
						tmp = double(pt[j].y1) + double(x - pt[j].x1) * (pt[j].y2 - pt[j].y1) / (pt[j].x2 - pt[j].x1);
						if (tmp < y && (miny == -1.0 || miny > tmp)){
							miny = tmp;
							k = j;
						}
					}
				}

				if (miny == -1.0) break;
				if (pt[k].y1 > pt[k].y2){
					x = pt[k].x2;
					y = pt[k].y2;
				}else{
					x = pt[k].x1;
					y = pt[k].y1;
				}
			}

			printf("%d\n", x);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
