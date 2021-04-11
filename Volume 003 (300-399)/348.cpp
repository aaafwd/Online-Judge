/* @JUDGE_ID: 19899RK 348 C++ "By Anadan" */
// Optimal Array Multiplication Sequence
// Accepted (0.383 seconds using as much as 388 kbytes)

#include <stdio.h>

int N;
struct Matrix{
	int a, b;
}A[10];
int min[10][10], brackets[10][10], tmp;

int getmin(int i, int j){
	int k;

	if (min[i][j] != -1) return min[i][j];

	min[i][j] = getmin(i + 1, j) + A[i].a * A[j].b * A[i].b;
	brackets[i][j] = i;

	for (k = i + 1; k < j; ++k){
		tmp = getmin(i, k) + getmin(k + 1, j) + A[i].a * A[j].b * A[k].b;
		if (min[i][j] > tmp){
			min[i][j] = tmp;
			brackets[i][j] = k;
		}
	}

	return min[i][j];
}

void outprint(int i, int j){
	if (i == j){
		printf("A%d", i + 1);
		return;
	}

	putchar('(');
	outprint(i, brackets[i][j]);
	printf(" x ");
	outprint(brackets[i][j] + 1, j);
	putchar(')');
}

int main(){
	int i, j, set = 0;

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i) scanf("%d%d\n", &A[i].a, &A[i].b);
		for (i = 0; i < N; ++i){
			for (j = 0; j < N; ++j) min[i][j] = brackets[i][j] = -1;
			min[i][i] = 0;
		}

		getmin(0, N - 1);

		printf("Case %d: ", ++set);
		outprint(0, N - 1);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
