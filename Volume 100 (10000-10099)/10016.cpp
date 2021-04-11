/* @JUDGE_ID: 19899RK 10016 C++ "By Anadan" */
// Flip-Flop the Squarelotron
// Accepted (0.350 seconds using as much as 436 kbytes)

#include <stdio.h>

int map[100][100], N;

void rotate(int C, int ring){
	int r1 = (N + 1)/2 - ring - 1, r2 = N/2 + ring, sz = r2 - r1 + 1, i, j;

	switch (C){
	case 1:
		for (i = r1; i <= r2; ++i){
			j = map[r1][i]; map[r1][i] = map[r2][i]; map[r2][i] = j;
		}

		for (i = 1; i < sz/2; ++i){
			j = map[r1 + i][r1]; map[r1 + i][r1] = map[r2 - i][r1]; map[r2 - i][r1] = j;
			j = map[r1 + i][r2]; map[r1 + i][r2] = map[r2 - i][r2]; map[r2 - i][r2] = j;
		}
		break;
	case 2:
		for (i = r1; i <= r2; ++i){
			j = map[i][r1]; map[i][r1] = map[i][r2]; map[i][r2] = j;
		}

		for (i = 1; i < sz/2; ++i){
			j = map[r1][r1 + i]; map[r1][r1 + i] = map[r1][r2 - i]; map[r1][r2 - i] = j;
			j = map[r2][r1 + i]; map[r2][r1 + i] = map[r2][r2 - i]; map[r2][r2 - i] = j;
		}
		break;
	case 3:
		for (i = 1; i < sz - 1; ++i){
			j = map[r1][r1 + i]; map[r1][r1 + i] = map[r1 + i][r1]; map[r1 + i][r1] = j;
			j = map[r2][r2 - i]; map[r2][r2 - i] = map[r2 - i][r2]; map[r2 - i][r2] = j;
		}
		j = map[r1][r2]; map[r1][r2] = map[r2][r1]; map[r2][r1] = j;
		break;
	case 4:
		for (i = 1; i < sz - 1; ++i){
			j = map[r1][r2 - i]; map[r1][r2 - i] = map[r1 + i][r2]; map[r1 + i][r2] = j;
			j = map[r2][r1 + i]; map[r2][r1 + i] = map[r2 - i][r1]; map[r2 - i][r1] = j;
		}
		j = map[r1][r1]; map[r1][r1] = map[r2][r2]; map[r2][r2] = j;
		break;
	default:
		printf("Error!\n");
		break;
	}
}

int main(){
	int M, R, T, C, i, j;

	scanf("%d\n", &M);
	while (M--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j)
			scanf("%d\n", &map[i][j]);
		R = (N + 1) >> 1;
		for (j = R - 1; j >= 0; --j){
			scanf("%d", &T);
			for (i = 0; i < T; ++i){
				scanf("%d", &C);
				rotate(C, j);
			}
		}

		for (i = 0; i < N; ++i){
			for (j = 0; j < N - 1; ++j) printf("%d ", map[i][j]);
			printf("%d\n", map[i][j]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
