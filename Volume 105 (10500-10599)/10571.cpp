/* @JUDGE_ID: 19899RK 10571 C++ "By Anadan" */
// Products
// Accepted (0.191 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

int map[10][10], N, x[10], y[10];
char mask[10], nummask[1001];

int generate(int row){
	int i, j, k, m, i0;
	if (row == N) return 1;

	for (i0 = 0; i0 < N; ++i0) if (mask[i0] != 2) break;

	for (k = 1; k <= y[row]; ++k){
		if (nummask[k]) continue;
		if (y[row] % k) continue;
		m = y[row] / k;
		if (nummask[m]) continue;
		nummask[k] = nummask[m] = 1;

		for (i = i0; i < N; ++i){
			if (mask[i] == 2) continue;
			if (x[i] % k) continue;
			if (mask[i] == 1 && k != x[i]) continue;

			x[i] /= k;
			++mask[i];

			for (j = i + 1; j < N; ++j){
				if (mask[j] == 2) continue;
				if (x[j] % m) continue;
				if (mask[j] == 1 && m != x[j]) continue;

				x[j] /= m;
				++mask[j];

				map[row][i] = k;
				map[row][j] = m;
				if (generate(row + 1)) return 1;
				map[row][i] = 0;
				map[row][j] = 0;

				--mask[j];
				x[j] *= m;
			}

			--mask[i];
			x[i] *= k;
		}

		nummask[k] = nummask[m] = 0;
	}

	return 0;
}

int main(){
	int i, j;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d", x + i);
		for (i = 0; i < N; ++i) scanf("%d", y + i);

		memset(map, 0, sizeof(map));
		memset(mask, 0, sizeof(mask));
		memset(nummask, 0, sizeof(nummask));

		generate(0);
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j) printf("%d ", map[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
