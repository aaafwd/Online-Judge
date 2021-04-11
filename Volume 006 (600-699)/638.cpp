/* @JUDGE_ID: 19899RK 638 C++ "By Anadan" */
// Finding Rectangles
// Accepted (0.640 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <stdlib.h>

struct Rect{
	char c;
	int x, y;
}pt[26];

int sort_function(const void *a, const void *b){
	if (((Rect *)a)->c < ((Rect *)b)->c) return -1;
	return 1;
}

int main(){
	char solved;
	int i, j, k, l, N, set = 0, printed;

	while (scanf("%d\n", &N) > 0){
		if (N == 0) break;
		for (i = 0; i < N; i++) scanf("%c %d %d\n", &pt[i].c, &pt[i].x, &pt[i].y);
		qsort((void *)pt, N, sizeof(Rect), sort_function);
		printf("Point set %d:", ++set);
		solved = 0;
		printed = 0;
		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++){
				if (pt[i].y != pt[j].y) continue;
				if (pt[i].x >= pt[j].x) continue;
				for (k = 0; k < N; k++){
					if (pt[j].x != pt[k].x) continue;
					if (pt[j].y <= pt[k].y) continue;
					for (l = 0; l < N; l++){
						if (pt[l].y != pt[k].y) continue;
						if (pt[l].x != pt[i].x) continue;
						if (!solved) putchar('\n');
						if (printed == 10){
							printed = 1;
							putchar('\n');
						}else ++printed;
						printf(" %c%c%c%c", pt[i].c, pt[j].c, pt[k].c, pt[l].c);
						solved = 1;
					}
				}
			}
		}
		if (!solved) printf(" No rectangles\n"); else putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
