/* @JUDGE_ID: 19899RK 10496 C++ "By Anadan" */ 
// Collecting Beepers
// Accepted (0.018 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int min, N;
struct Point{
	int x, y;
}pt[20];
char mask[20];

inline int _abs(int x) { return (x < 0) ? (-x) : (x); }
inline int getdist(int i, int j) { return _abs(pt[i].x - pt[j].x) + _abs(pt[i].y - pt[j].y); }

void generate(int n, int last, int curr){
	int i;

	if (min != -1 && curr >= min) return;
	if (n == N){
		curr += getdist(0, last);
		if (min == -1 || min > curr) min = curr;
		return;
	}

	for (i = 1; i < N; ++i){
		if (mask[i]) continue;
		mask[i] = 1;
		generate(n + 1, i, curr + getdist(last, i));
		mask[i] = 0;
	}
}

int main(){
	int set, i;

	scanf("%d", &set);
	while (set--){
		scanf("%*d%*d%d%d%d", &pt[0].x, &pt[0].y, &N);
		for (++N, i = 1; i < N; ++i){
			scanf("%d%d", &pt[i].x, &pt[i].y);
		}

		min = -1;
		memset(mask, 0, sizeof(mask));
		generate(1, 0, 0);
		printf("The shortest path has length %d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
