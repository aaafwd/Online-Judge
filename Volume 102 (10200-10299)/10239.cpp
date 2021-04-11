/* @JUDGE_ID: 19899RK 10239 C++ "By Anadan" */ 
// The Book-shelver's Problem
// Accepted (0.596 seconds using as much as 400 kbytes)

#include <stdio.h>

struct Shelves{
	int h, w, res;
}pt[1001];

int main(){
	int N, i, j;
	int W, hh, ww;

	pt[0].h = pt[0].w = pt[0].res = 0.0;
	while (scanf("%d%d.%d\n", &N, &i, &j) == 3 && N){
		W = 10000 * i + j;
		for (i = 1; i <= N; ++i){
			scanf("%d.%d", &j, &hh); hh += 10000 * j;
			scanf("%d.%d", &j, &ww); ww += 10000 * j;
			pt[i].h = hh;
			pt[i].w = ww;
			pt[i].res = pt[i - 1].res + hh;

			for (j = i - 1; j > 0; --j){
				ww += pt[j].w;
				if (ww > W) break;
				if (hh < pt[j].h) hh = pt[j].h;
				if (pt[i].res > pt[j - 1].res + hh){
					pt[i].res = pt[j - 1].res + hh;
				}
			}
		}

		printf("%.4lf\n", double(pt[N].res) * 0.0001);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
