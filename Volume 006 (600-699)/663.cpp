/* @JUDGE_ID: 19899RK 663 C++ "By Anadan" */
// Sorting Slides
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Slide{
	int x1, x2, y1, y2;
}pt[26];
int N, sum1[26], sum2[26];
char map[26][26];

int relax(){
	int i, j, k, m;
	char mask1[26], mask2[26];

	for (i = 0; i < N; ++i){
		if (sum1[i] == 0) continue;
		for (j = 0; j < N; ++j){
			if (map[i][j]) mask1[j] = 1; else mask1[j] = 0;
		}

		memset(mask2, 0, 26);
		mask2[i] = 1;
		for (m = 1, j = i + 1; j < N && m != sum1[i]; ++j){
			if (sum1[j] != sum1[i]) continue;
			for (k = 0; k < N; ++k) if (map[i][k] ^ map[j][k]) break;
			if (k < N) continue;
			mask2[j] = 1;
			++m;
		}

		if (m != sum1[i]) continue;
		i = j = 0;
		break;
	}

	if (i >= N) for (j = 0; j < N; ++j){
		if (sum2[j] == 0) continue;
		for (i = 0; i < N; ++i){
			if (map[i][j]) mask2[i] = 1; else mask2[i] = 0;
		}

		memset(mask1, 0, 26);
		mask1[j] = 1;
		for (m = 1, i = j + 1; i < N && m != sum2[j]; ++i){
			if (sum2[i] != sum2[j]) continue;
			for (k = 0; k < N; ++k) if (map[k][i] ^ map[k][j]) break;
			if (k < N) continue;
			mask1[i] = 1;
			++m;
		}

		if (m != sum2[j]) continue;
		i = j = 0;
		break;
	}

	if (i || j) return 0;
	for (i = 0; i < N; ++i){
		if (!mask2[i]) continue;
		for (j = 0; j < N; ++j){
			if (map[i][j]){
				map[i][j] = 0;
				--sum1[i];
				--sum2[j];
			}
		}
	}

	for (j = 0; j < N; ++j){
		if (!mask1[j]) continue;
		for (i = 0; i < N; ++i){
			if (map[i][j]){
				map[i][j] = 0;
				--sum1[i];
				--sum2[j];
			}
		}
	}

	return 1;
}

int main(){
	int set = 0, i, j, x, y, nums[26];

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			scanf("%d%d%d%d\n", &pt[i].x1, &pt[i].x2, &pt[i].y1, &pt[i].y2);
			nums[i] = sum1[i] = sum2[i] = 0;
			for (j = 0; j < N; ++j) map[i][j] = 0;
		}

		for (i = 0; i < N; ++i){
			scanf("%d%d\n", &x, &y);
			for (j = 0; j < N; ++j){
				if (pt[j].x1 < x && x < pt[j].x2 && pt[j].y1 < y && y < pt[j].y2){
					map[i][j] = 1;
					++sum1[i];
					++sum2[j];
				}
			}
		}

		x = 0;
		while (1){
			for (i = 0; i < N; ++i) if (sum1[i] == 1) break;
			if (i < N){
				for (j = 0; j < N; ++j) if (map[i][j]) break;
				x = 1;
				nums[j] = i + 1;
				for (i = 0; i < N; ++i){
					if (map[i][j]){
						map[i][j] = 0;
						--sum1[i];
						--sum2[j];
					}
				}
			}else{
				for (j = 0; j < N; ++j) if (sum2[j] == 1) break;
				if (j >= N){
					if (relax()) continue; else break;
				}
				for (i = 0; i < N; ++i) if (map[i][j]) break;
				x = 1;
				nums[j] = i + 1;
				for (j = 0; j < N; ++j){
					if (map[i][j]){
						map[i][j] = 0;
						--sum1[i];
						--sum2[j];
					}
				}
			}
		}

		printf("Heap %d\n", ++set);
		if (x == 0) printf("none\n\n");
		else{
			for (i = 0; i < N; ++i) if (nums[i]) break;
			printf("(%c,%d)", 'A' + i, nums[i]);
			for (++i; i < N; ++i) if (nums[i]) printf(" (%c,%d)", 'A' + i, nums[i]);
			printf("\n\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
