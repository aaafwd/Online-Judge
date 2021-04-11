/* @JUDGE_ID: 19899RK 10816 C++ "By Anadan" */
// Travel in Desert
// Accepted (0.477 seconds using as much as 740 kbytes)

#include <stdio.h>
#include <string.h>
#define EPS 1e-7

struct tag_map {
	int start, end;
} map[128][128];
int N, src, dst, next[11000], pi[128];
double R[11000], D[11000], solLen, solTemp;

double getPath(int i, int j, double threshold) {
	int k = map[i][j].start;
	double res = -1;

	while (k != -1) {
		if (R[k] <= threshold+EPS) {
			if (res < 0 || res > D[k]) res = D[k];
		}
		k = next[k];
	}
	return res;
}

// Dijkstra algorithm
int findway(double threshold) {
	int i, j;
	double ro[100], min, tmp;
	char passed[100];

	memset(passed, 0, N);
	passed[src] = 1;

	for (i = 0; i < N; ++i) {
		pi[i] = src;
		ro[i] = getPath(src, i, threshold);
	}

	while (1) {
		min = -1;
		for (i = 0; i < N; ++i){
			if (passed[i] || ro[i] < 0) continue;
			if (min < 0 || min > ro[i]){
				min = ro[i];
				j = i;
			}
		}

		if (j == dst || min < 0) break;
		passed[j] = 1;

		for (i = 0; i < N; ++i){
			if (passed[i]) continue;
			tmp = getPath(j, i, threshold);
			if (tmp < 0) continue;
			if (ro[i] < 0 || ro[i] > ro[j] + tmp) {
				ro[i] = ro[j] + tmp;
				pi[i] = j;
			}
		}
	}

	if (ro[dst] < 0) return 0;
	solLen = ro[dst];
	solTemp = threshold;

	return 1;
}

void outputWay(int i) {
	if (pi[i] == i) printf("%d", i+1);
	else {
		outputWay(pi[i]);
		printf(" %d", i+1);
	}
}

int main() {
	int E, i, j, sp;
	double r, d, minR, maxR;

	while (scanf("%d%d%d%d", &N, &E, &src, &dst) == 4) {
		--src; --dst;

		memset(map, -1, sizeof(map));
		sp = 0;
		while (E-- > 0) {
			scanf("%d%d%lf%lf", &i, &j, &r, &d);

			--i; --j;
			R[sp] = r;
			D[sp] = d;
			next[sp] = -1;

			if (map[i][j].start == -1) {
				map[i][j].start = map[i][j].end = sp;
			} else {
				next[map[i][j].end] = sp;
				map[i][j].end = sp;
			}

			++sp;
			map[j][i] = map[i][j];
		}

		if (src == dst) {
			printf("%d\n0.0 0.0\n", src+1);
			continue;
		}

		minR = maxR = R[0];
		for (i = 1; i < sp; ++i) {
			if (minR > R[i]) minR = R[i];
			if (maxR < R[i]) maxR = R[i];
		}

		while (minR < maxR - EPS) {
			r = (minR + maxR) * 0.5;
			if (findway(r)) maxR = r;
			else minR = r;
		}
		r = maxR+EPS;
		findway(r);

		outputWay(dst);
		printf("\n%.1lf %.1lf\n", solLen, solTemp);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
