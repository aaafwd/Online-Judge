/* @JUDGE_ID: 19899RK 10051 C++ "By Anadan" */ 
// Tower of Cubes
// Accepted (0.674 seconds using as much as 420 kbytes)

#include <stdio.h>

struct Cube{
	int color[6], h[6], next[6];
}pt[500];

const char sizes[6][7] = {
	"front", "back", "left", "right", "top", "bottom"
};

int main(){
	int set = 0, N, i, j, k, l, max, maxcube;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			for (j = 0; j < 6; ++j){
				scanf("%d", pt[i].color + j);
				pt[i].h[j] = 1;
				pt[i].next[j] = -1;
			}
		}

		max = 1; maxcube = 0;
		for (i = N - 1; i >= 0; --i){
			for (j = 0; j < 6; ++j){
				for (k = i + 1; k < N; ++k) for (l = 0; l < 6; ++l){
					if (pt[i].color[j ^ 1] == pt[k].color[l] && pt[i].h[j] < pt[k].h[l] + 1){
						pt[i].h[j] = pt[k].h[l] + 1;
						pt[i].next[j] = (k << 3) + l;
					}
				}

				if (max < pt[i].h[j]){
					max = pt[i].h[j];
					maxcube = (i << 3) + j;
				}
			}
		}

		if (set) putchar('\n');
		printf("Case #%d\n%d\n", ++set, max);

		for (l = 0; l < max; ++l){
			i = maxcube >> 3;
			j = maxcube & 7;
			printf("%d %s\n", i + 1, sizes[j]);
			maxcube = pt[i].next[j];
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
