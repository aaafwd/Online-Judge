/* @JUDGE_ID: 19899RK 10535 C++ "By Anadan" */
// Shooter
// Accepted (1.453 seconds using as much as 396 kbytes)

#include <stdio.h>

struct Wall{
	int x1, y1, x2, y2;
}pt[500];
int N, sx, sy, max;

void shoot(int x0, int y0){
	int i, det, t1, t2, res = 0;

	for (i = 0; i < N; ++i){
		det = (x0 - sx) * (pt[i].y1 - pt[i].y2) - (y0 - sy) * (pt[i].x1 - pt[i].x2);
		t1  = (pt[i].x1 - sx) * (pt[i].y1 - pt[i].y2) - (pt[i].y1 - sy) * (pt[i].x1 - pt[i].x2);
		t2  = (x0 - sx) * (pt[i].y1 - sy) - (y0 - sy) * (pt[i].x1 - sx);
		if (det < 0) { det = -det; t1 = -t1; t2 = -t2; }
		if (det){
			if (t1 >= 0 && t2 >= 0 && t2 <= det) ++res;
		}else{
			if (t2 == 0){
				if (x0 != sx){
					if ((pt[i].x1 > sx) ^ (x0 < sx)) ++res;
				}else{
					if ((pt[i].y1 > sy) ^ (y0 < sy)) ++res;
				}
			}
		}
	}

	if (max < res) max = res;
}

int main(){
	int i;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			scanf("%d%d%d%d", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
		}

		scanf("%d%d", &sx, &sy);

		max = 0;
		for (i = 0; i < N; ++i){
			shoot(pt[i].x1, pt[i].y1);
			shoot(pt[i].x2, pt[i].y2);
		}

		printf("%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
