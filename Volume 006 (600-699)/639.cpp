/* @JUDGE_ID: 19899RK 639 C++ "By Anadan" */
// Don't Get Rooked
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int N, max, k;
char map[4][5];

void setmaxrooks(int i, int j0, int rooks){
	int j;

	if (i == N){
		if (max < rooks) max = rooks;
		return;
	}

	for (; i < N; ++i){
		for (j = j0; j < N; ++j){
			if (map[i][j] == 'X') continue;
			for (k = i - 1; k >= 0; --k){
				if (map[k][j] == 'X') k = 0;
				else if (map[k][j] == '!') break;
			}
			if (k >= 0) continue;

			for (k = j + 1; k < N; ++k) if (map[i][k] == 'X') break;
			while (map[i][k] == 'X') ++k;
			map[i][j] = '!';
			if (k < N) setmaxrooks(i, k, rooks + 1);
			else setmaxrooks(i + 1, 0, rooks + 1);
			map[i][j] = '.';
		}
		j0 = 0;
	}
}

int main(){
	int i;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%s\n", map[i]);
		max = 0;
		setmaxrooks(0, 0, 0);
		printf("%d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
