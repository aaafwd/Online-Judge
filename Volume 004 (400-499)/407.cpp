/* @JUDGE_ID: 19899RK 407 C++ "By Anadan" */ 
// Gears on a Board
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Gear{
	int x, y, irad, orad;
	double w;
}pt[21];
char rotated[21], map[21][21];

inline int sqr(int x) { return x * x; }

int main(){
	int set = 0, N, i, j, a, b, c, queue[21];
	double w;

	while (scanf("%d%d%d%d%d\n", &pt[0].x, &pt[0].y, &pt[0].irad, &pt[0].orad, &j) == 5){
		pt[0].w = double(j);
		rotated[0] = 1;
		scanf("%d\n", &N); ++N;
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) map[i][j] = 0;
		for (i = 1; i < N; ++i){
			scanf("%d%d%d%d\n", &pt[i].x, &pt[i].y, &pt[i].irad, &pt[i].orad);
			rotated[i] = 0;
			if (rotated[0]){
				for (j = 0; j < i; ++j){
					a = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
					b = sqr(pt[i].irad + pt[j].irad);
					c = sqr(pt[i].orad + pt[j].orad);
					if (a < b || a < c) break;
					if (a == b) map[i][j] = map[j][i] |= 1;
					if (a == c) map[i][j] = map[j][i] |= 2;
				}

				if (j < i) rotated[0] = 0;
			}
		}

		printf("Simulation #%d\n", ++set);
		if (rotated[0]){
			i = 0; j = 1; queue[0] = 0;
			while (i < j){
				a = queue[i++];
				for (b = 0; b < N; ++b){
					if (!map[a][b]) continue;
					if (map[a][b] == 1) w = -pt[a].w * pt[a].irad / pt[b].irad;
					else if (map[a][b] == 2) w = -pt[a].w * pt[a].orad / pt[b].orad;
					else{
						if (pt[a].irad * pt[b].orad != pt[b].irad * pt[a].orad){
							j = 0; break;
						}
						w = -pt[a].w * pt[a].irad / pt[b].irad;
					}

					if (rotated[b]){
						if (fabs(pt[b].w - w) > 1e-12){
							j = 0; break;
						}
					}else{
						pt[b].w = w;
						rotated[b] = 1;
						queue[j++] = b;
					}
				}
			}

			if (j){
				for (i = 1; i < N; ++i){
					printf("%2d: ", i);
					if (!rotated[i]) printf("Warning -- Idle Gear\n");
					else{
						if (pt[i].w < 0){
							putchar('L');
							pt[i].w = -pt[i].w;
						}else putchar('R');

						printf(" %.2lf\n", pt[i].w);
					}
				}
				putchar('\n');

			}else printf("Error -- Conflicting Gear Rotation\n\n");

		}else printf("Error -- Overlapping Gears\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
