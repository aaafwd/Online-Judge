/* @JUDGE_ID: 19899RK 10022 C++ "By Anadan" */
// Delta-wave
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int main() {
	int set, N, M, row1, row2, pos1, pos2, res, center, R;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &M, &N);
		if (M > N) { pos1 = M; M = N; N = pos1; }

		row1 = (int)sqrt(M);
		if (row1 * row1 < M) ++row1;
		pos1 = M - (row1 - 1)*(row1 - 1) - 1;

		row2 = (int)sqrt(N);
		if (row2 * row2 < N) ++row2;
		pos2 = N - (row2 - 1)*(row2 - 1) - 1;

		if (row1 == row2 || pos1 == pos2) {
			res = pos2 - pos1 + (row2 - row1) * 2;
		} else {
			center = pos2 - (row2 - row1);
			R = row2 - row1 + 1 - (pos2 & 1);

			if (center - R <= pos1 && pos1 <= center + R) {
				res = (row2 - row1) * 2 - (pos2 & 1) + (pos1 & 1);
			} else if (pos1 < center) { // pos1 < center - R
				// res = (row2 - row1)*2 - (pos2 & 1) + 1 + center - R - pos1;
				res = row2 - row1 + center - pos1;
			} else { // pos1 > center + R
				// res = (row2 - row1)*2 - (pos2 & 1) + 1 + pos1 - center - R;
				res = row2 - row1 + pos1 - center;
			}
		}

		printf("%d\n", res);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
