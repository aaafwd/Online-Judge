/* @JUDGE_ID: 19899RK 10306 C++ "By Anadan" */ 
// e-Coins
// Accepted (0.059 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int N, map[301][301];
struct Ecoin{
	int x, y;
}pt[40];

int getcoins(int x, int y, int i){
	int min = -1, tmp;

	if (map[x][y] != -1) return map[x][y];
	if (map[x][y] == -2) return -1;

	for (; i < N; ++i){
		if (x >= pt[i].x && y >= pt[i].y){
			tmp = getcoins(x - pt[i].x, y - pt[i].y, i);
			if (tmp >= 0){
				if (min == -1 || min > tmp) min = tmp;
			}
		}
	}

	if (min == -1) map[x][y] = -2; else map[x][y] = ++min;
	return min;
}

int main(){
	int set, i, j, k, S, min;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d\n", &k, &S);
		for (N = i = 0; i < k; ++i){
			scanf("%d%d\n", &pt[N].x, &pt[N].y);
			if (pt[N].x || pt[N].y) ++N;
		}

		for (i = 0; i <= S; ++i) for (j = 0; j <= S; ++j) map[i][j] = -1;
		map[0][0] = 0;

		min = -1;
		S *= S;
		for (i = k = 0; k <= S; ++i){
			j = (int)sqrt(S - k);
			if (k + j * j == S){
				j = getcoins(i, j, 0);
				if (j >= 0){
					if (min == -1 || min > j) min = j;
				}
			}
			k += i + i + 1;
		}

		if (min < 0) printf("not possible\n");
		else printf("%d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
