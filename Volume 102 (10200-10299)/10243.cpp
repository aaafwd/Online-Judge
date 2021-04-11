/* @JUDGE_ID: 19899RK 10243 C++ "By Anadan" */
// Fire! Fire!! Fire!!!
// Accepted (0.029 seconds with low memory spent)

#include <stdio.h>

int N, start[2048], end[2048], vertexes[2048], sp, res;

void myscanf(int &x){
	int i;
	while ((x = getchar()) < '0' || x > '9');
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int dfs(int u, int prev) {
	int i, v, leaf = 1, needed = 0;

	for (i = start[u]; i < end[u]; ++i) {
		v = vertexes[i];
		if (v == prev) continue;
		leaf = 0;
		if (!dfs(v, u)) needed = 1;
	}
	if (!leaf && needed) { ++res; return 1; }

	return 0;
}

int main() {
	int i, j, M;

	while (scanf("%d", &N) == 1 && N) {
		for (sp = i = 0; i < N; ++i) {
			myscanf(M);
			start[i] = sp;
			while (M--) {
				myscanf(j); --j;
				vertexes[sp++] = j;
			}
			end[i] = sp;
		}

		res = 0;
		dfs(0, -1);
		if (res == 0) res = 1;
		printf("%d\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
