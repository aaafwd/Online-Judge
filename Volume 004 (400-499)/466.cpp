/* @JUDGE_ID: 19899RK 466 C++ "By Anadan" */ 
// Mirror, Mirror
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char map1[10][11], map2[10][11];

int rotation(){
	int i, j;

	for (i = 0; i < N; ++i){
		for (j = 0; j < N; ++j) if (map1[i][j] != map2[j][N - 1 - i]) break;
		if (j < N) break;
	}
	if (i == N) return 90;

	for (i = 0; i < N; ++i){
		for (j = 0; j < N; ++j) if (map1[i][j] != map2[N - 1 - i][N - 1 - j]) break;
		if (j < N) break;
	}
	if (i == N) return 180;

	for (i = 0; i < N; ++i){
		for (j = 0; j < N; ++j) if (map1[i][j] != map2[N - 1 - j][i]) break;
		if (j < N) break;
	}
	if (i == N) return 270;

	return 0;
}

int reflection(){
	int i, j, k;

	for (i = 0; i < N; ++i){
		for (j = 0, k = N - 1; j < k; ++j, --k){
			map1[j][i] ^= map1[k][i] ^= map1[j][i] ^= map1[k][i];
		}
	}

	for (i = 0; i < N; ++i) if (strcmp(map1[i], map2[i])) break;
	return (i == N);
}

int main(){
	int set = 0, i;

	while (scanf("%d\n", &N) == 1){
		printf("Pattern %d was ", ++set);
		for (i = 0; i < N; ++i) scanf("%s %s\n", map1[i], map2[i]);
		for (i = 0; i < N; ++i) if (strcmp(map1[i], map2[i])) break;
		if (i == N) printf("preserved.\n");
		else{
			i = rotation();
			if (i) printf("rotated %d degrees.\n", i);
			else{
				if (reflection()) printf("reflected vertically.\n");
				else{
					i = rotation();
					if (i) printf("reflected vertically and rotated %d degrees.\n", i);
					else printf("improperly transformed.\n");
				}
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
