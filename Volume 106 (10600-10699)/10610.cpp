/* @JUDGE_ID: 19899RK 10610 C++ "By Anadan" */
// Gopher and Hawks
// Accepted (0.184 seconds using as much as 416 kbytes)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Point{
	double x, y;
} pt[1010];
int N, vertexes[1010];
char mask[1010];
double s;

inline double sqr(double x) { return x * x; }

int reachable(int i, int j){
	double tmp = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
	return tmp <= s;
}

int dowave(){
	int i = 0, j = 1, v, k, step = 0, count;

	vertexes[0] = 0;
	memset(mask, 0, N);
	mask[0] = 1;

	while (i < j){
		count = 0;
		while (i < j){
			v = vertexes[i++];
			if (v == 1) return step;
			for (k = 1; k < N; ++k){
				if (mask[k]) continue;
				if (reachable(v, k)){
					mask[k] = 1;
					vertexes[j + count++] = k;
				}
			}
		}

		++step;
		j += count;
	}

	return 0;
}

int myscanf(double & x, double & y){
	int c;
	while ((c = getchar()) != EOF && c != '\n' && isspace(c));
	if (c == EOF || c == '\n') return 0;
	ungetc(c, stdin);
	scanf("%lf%lf", &x, &y);
	while ((c = getchar()) != EOF && c != '\n');
	return 1;
}

int main(){
	int v, m;

	while (scanf("%d%d\n", &v, &m) == 2 && (v || m)){
		s = sqr(60.0 * v * m);
		for (N = 0; myscanf(pt[N].x, pt[N].y); ++N);

		v = dowave();
		if (v) printf("Yes, visiting %d other holes.\n", v - 1);
		else puts("No.");
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
