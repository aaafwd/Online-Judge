/* @JUDGE_ID: 19899RK 10078 C++ "By Anadan" */ 
// The Art Gallery
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int N;
struct POINT{
	int x, y;
}ptr[50];

int isConvex(){
	int i, j;
	long det, it1, it2;

	for (i = 0; i < N - 1; ++i){
		j = (i + 1) % N;
		det = (ptr[j].x - ptr[i].x) * (ptr[j].y - ptr[(j + 1) % N].y) - (ptr[j].x - ptr[(j+1)%N].x) * (ptr[j].y - ptr[i].y);
		it1 = (ptr[j].x - ptr[i].x) * (ptr[j].y - ptr[(j + 1) % N].y) - (ptr[j].x - ptr[(j+1)%N].x) * (ptr[j].y - ptr[i].y);
		it2 = (ptr[i + 1].x - ptr[i].x) * (ptr[j].y - ptr[i].y) - (ptr[j].x - ptr[i].x) * (ptr[i + 1].y - ptr[i].y);
		if ((!det) && (!it1) && (!it2)) return 0;
		for (j = 0; j < N; ++j){
			if (i == j) continue;
			if (i == (j + 1) % N) continue;
			if (i == (N + j - 1) % N) continue;
			det = (ptr[(i + 1) % N].x - ptr[i].x) * (ptr[j].y - ptr[(j + 1) % N].y) - (ptr[j].x - ptr[(j + 1) % N].x) * (ptr[(i + 1) % N].y - ptr[i].y);
			it1 = (ptr[j].x - ptr[i].x) * (ptr[j].y - ptr[(j + 1) % N].y) - (ptr[j].x - ptr[(j + 1) % N].x) * (ptr[j].y - ptr[i].y);
			it2 = (ptr[i + 1].x - ptr[i].x) * (ptr[j].y - ptr[i].y) - (ptr[j].x - ptr[i].x) * (ptr[i + 1].y - ptr[i].y);

			if (det == 0L){
				if ((!it1) && (!it2)) return 0;
				continue;
			}
			if (det < 0L){
				if ((it1 > 0L) || (it1 < det)) continue;
			}else if ((it1 < 0L) || (it1 > det)) continue;

			return 0;
		}
	}
	return 1;
}

int main(){
	int i;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			scanf("%d%d\n", &ptr[i].x, &ptr[i].y);
		}

		if (isConvex()) printf("No\n");
		else printf("Yes\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
