/* @JUDGE_ID: 19899RK 10603 C++ "By Anadan" */
// Fill
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int a, b, c, d, totsum, maxd;
int vertexes[65536], sum[65536];

inline int min(int x, int y) { if (x < y) return x; else return y; }

void tryfill(int x, int y, int filled, int & j){
	int tmp = (x << 8) + y;
	if (sum[tmp] != -1 && sum[tmp] <= filled) return;
	sum[tmp] = filled;
	vertexes[j++] = tmp;
}

inline int getmaxd(int x, int y, int z){
	if (x > y) x ^= y ^= x ^= y;
	if (x > z) x ^= z ^= x ^= z;
	if (y > z) y ^= z ^= y ^= z;
	if (x > d) return -1;
	if (y > d) return x;
	if (z > d) return y;
	return z;
}

void solve(){
	int i = 0, j = 1, x, y, tmp;

	totsum = maxd = 0;
	memset(sum, -1, sizeof(sum));
	sum[0] = 0;
	vertexes[0] = 0;

	while (i < j){
		x = vertexes[i] >> 8;
		y = vertexes[i] & 255;

		tmp = getmaxd(x, y, c - x - y);
		if (tmp < 0) { ++i; continue; }

		if (maxd < tmp || (maxd == tmp && totsum > sum[vertexes[i]])){
			maxd = tmp;
			totsum = sum[vertexes[i]];
		}

		tryfill(x - min(x, b - y), y + min(x, b - y), sum[vertexes[i]] + min(x, b - y), j);
		tryfill(x - min(x, x + y), y, sum[vertexes[i]] + min(x, x + y), j);
		tryfill(x + min(y, a - x), y - min(y, a - x), sum[vertexes[i]] + min(y, a - x), j);
		tryfill(x, y - min(y, x + y), sum[vertexes[i]] + min(y, x + y), j);
		tryfill(x + min(a - x, c - x - y), y, sum[vertexes[i]] + min(a - x, c - x - y), j);
		tryfill(x, y + min(b - y, c - x - y), sum[vertexes[i]] + min(b - y, c - x - y), j);

		++i;
	}
}

int main(){
	int set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		solve();
		printf("%d %d\n", totsum, maxd);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
