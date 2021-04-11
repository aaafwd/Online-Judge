/* @JUDGE_ID: 19899RK 672 C++ "By Anadan" */
// Gangsters
// Accepted (13.040 seconds using as much as 404 kbytes)
// Too much time !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Gangster{
	int T, S, P;
}pt[100], gang[100];
int N, K, T;

int sort_function(const void *a, const void *b){
	Gangster *ga = (Gangster *)a, *gb = (Gangster *)b;
	if (ga->T < gb->T) return -1;
	if (ga->T == gb->T && ga->S < gb->S) return -1;
	return 1;
}

int getgangster(int t, int s){
	int i = 0, j = N - 1, k;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (gang[k].T < t) i = k;
		else if (gang[k].T > t) j = k;
		else if (gang[k].S < s) i = k;
		else if (gang[k].S > s) j = k;
		else return gang[k].P;
	}

	if (gang[i].T == t && gang[i].S == s) return gang[i].P;
	if (gang[j].T == t && gang[j].S == s) return gang[j].P;
	return 0;
}

int getmaxsum(){
	int sum = 0, i, j, maxK, tmp, p[2][101], curr = 1;

	memset(p[0], 0, 101 * sizeof(int));
	memset(p[1], 0, 101 * sizeof(int));
	for (i = maxK = 1; i <= T; ++i){
		for (j = 0; j <= maxK; ++j){
			p[curr][j] = p[curr ^ 1][j] + getgangster(i, j);
			if (j){
				tmp = p[curr ^ 1][j - 1] + getgangster(i, j - 1);
				if (p[curr][j] < tmp) p[curr][j] = tmp;
			}
			if (j < maxK){
				tmp = p[curr ^ 1][j + 1] + getgangster(i, j + 1);
				if (p[curr][j] < tmp) p[curr][j] = tmp;
			}
		}

		curr ^= 1;
		if (i < K) ++maxK;
	}

	curr ^= 1;
	for (i = 1; i <= maxK; ++i) if (sum < p[curr][i]) sum = p[curr][i];
	return sum;
}

int main(){
	int i, M, set;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &N, &K, &T);
		for (i = 0; i < N; ++i) scanf("%d", &pt[i].T);
		for (i = 0; i < N; ++i) scanf("%d", &pt[i].P);
		for (i = 0; i < N; ++i) scanf("%d", &pt[i].S);
		qsort((void *)pt, N, sizeof(Gangster), sort_function);

		gang[0] = pt[0];
		for (M = i = 1; i < N; ++i){
			if (pt[i].T == pt[i - 1].T && pt[i].S == pt[i - 1].S){
				gang[M - 1].P += pt[i].P;
			}else gang[M++] = pt[i];
		}
		N = M;

		printf("%d\n", getmaxsum());
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
