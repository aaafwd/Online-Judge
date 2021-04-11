/* @JUDGE_ID: 19899RK 273 C++ "By Anadan" */
// Jack Straws
// Accepted (0.029 seconds with low memory spent)

#include <stdio.h>

struct Stick{
	int x1, y1, x2, y2;
}pt[12];

int connected(int i, int j){
	int det = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
	int it1 = (pt[j].x1 - pt[i].x1) * (pt[j].y1 - pt[j].y2) - (pt[j].y1 - pt[i].y1) * (pt[j].x1 - pt[j].x2);
	int it2 = (pt[i].x2 - pt[i].x1) * (pt[j].y1 - pt[i].y1) - (pt[i].y2 - pt[i].y1) * (pt[j].x1 - pt[i].x1);

	if (det < 0) { det = -det; it1 = -it1; it2 = -it2; }
	if (det == 0){
		if (it1 || it2) return 0;
		if (pt[i].x1 == pt[i].x2){
			it1 = pt[i].y1;
			it2 = pt[i].y2;
			if (it1 > it2) it1 ^= it2 ^= it1 ^= it2;
			if (it1 <= pt[j].y1 && pt[j].y1 <= it2) return 1;
			if (it1 <= pt[j].y2 && pt[j].y2 <= it2) return 1;
		}else{
			it1 = pt[i].x1;
			it2 = pt[i].x2;
			if (it1 > it2) it1 ^= it2 ^= it1 ^= it2;
			if (it1 <= pt[j].x1 && pt[j].x1 <= it2) return 1;
			if (it1 <= pt[j].x2 && pt[j].x2 <= it2) return 1;
		}

		return 0;
	}else{
		if (it1 < 0 || it1 > det || it2 < 0 || it2 > det) return 0;
		return 1;
	}
}

int main(){
	int i, j, k, set, N;
	char map[12][12];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d\n", &N);

		for (i = 0; i < N; ++i){
			scanf("%d%d%d%d\n", &pt[i].x1, &pt[i].y1, &pt[i].x2, &pt[i].y2);
			map[i][i] = 1;
			for (j = 0; j < i; ++j){
				if (connected(i, j)) map[i][j] = map[j][i] = 1;
				else map[i][j] = map[j][i] = 0;
			}
		}

		for (k = 0; k < N; ++k){
			for (i = 0; i < N; ++i){
				if (i == k || map[i][k] == 0) continue;
				for (j = 0; j < N; ++j){
					if (j == k || map[k][j] == 0) continue;
					map[i][j] = 1;
				}
			}
		}

		while (scanf("%d%d\n", &i, &j) == 2){
			if (i == 0 && j == 0) break;
			if (map[i - 1][j - 1]) printf("CONNECTED\n");
			else printf("NOT CONNECTED\n");
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
