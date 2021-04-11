/* @JUDGE_ID: 19899RK 10575 C++ "By Anadan" */
// Polylops
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>

struct Point{
	int x, y;
}pt[1000], p, a;
int N;

int main(){
	int set = 0, i, j, tmp, res, x, y;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);

		res = 0;
		if (N & 1){
			for (i = 0; i < N; ++i){
				p.x = pt[i].x + pt[(i+1)%N].x;
				p.y = pt[i].y + pt[(i+1)%N].y;
				a.x = pt[(i+1)%N].y - pt[i].y;
				a.y = -pt[(i+1)%N].x + pt[i].x;

				for (j = 1; j < (N+1) / 2; ++j){
					tmp = (pt[(i+1+j)%N].x - pt[(N+i-j)%N].x)*a.x + (pt[(i+1+j)%N].y - pt[(N+i-j)%N].y)*a.y;
					if (tmp) break;
					x = pt[(i+1+j)%N].x + pt[(N+i-j)%N].x - p.x;
					y = pt[(i+1+j)%N].y + pt[(N+i-j)%N].y - p.y;
					tmp = x * a.y - y * a.x;
					if (tmp) break;
				}

				if (j == (N+1) / 2) ++res;
			}
		}else{
			for (i = 0; i < N / 2; ++i){
				p.x = pt[i].x + pt[i].x;
				p.y = pt[i].y + pt[i].y;
				a.x = pt[i + N/2].x - pt[i].x;
				a.y = pt[i + N/2].y - pt[i].y;

				for (j = 1; j < N / 2; ++j){
					tmp = (pt[i+j].x - pt[(N+i-j)%N].x)*a.x + (pt[i+j].y - pt[(N+i-j)%N].y)*a.y;
					if (tmp) break;
					x = pt[i+j].x + pt[(N+i-j)%N].x - p.x;
					y = pt[i+j].y + pt[(N+i-j)%N].y - p.y;
					tmp = x * a.y - y * a.x;
					if (tmp) break;
				}

				if (j == N / 2) ++res;
			}

			for (i = 0; i < N / 2; ++i){
				p.x = pt[i].x + pt[(i+1)%N].x;
				p.y = pt[i].y + pt[(i+1)%N].y;
				a.x = pt[(i+1)%N].y - pt[i].y;
				a.y = -pt[(i+1)%N].x + pt[i].x;

				for (j = 1; j < N / 2; ++j){
					tmp = (pt[(i+1+j)%N].x - pt[(N+i-j)%N].x)*a.x + (pt[(i+1+j)%N].y - pt[(N+i-j)%N].y)*a.y;
					if (tmp) break;
					x = pt[(i+1+j)%N].x + pt[(N+i-j)%N].x - p.x;
					y = pt[(i+1+j)%N].y + pt[(N+i-j)%N].y - p.y;
					tmp = x * a.y - y * a.x;
					if (tmp) break;
				}

				if (j == N / 2) ++res;
			}
		}

		printf("Polygon #%d has %d symmetry line(s).\n", ++set, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
