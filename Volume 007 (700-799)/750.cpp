/* @JUDGE_ID: 19899RK 750 C++ "By Anadan" */
// 8 Queens Chess Problem
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

char solves[92][9];
int A[8];

int isntOk(int n){
	int i;
	for (i = 0; i < n; i++){
		if (A[n] == A[i]) return 1;
		if ((A[n] - n) == (A[i] - i)) return 1;
		if ((A[n] + n) == (A[i] + i)) return 1;
	}
	return 0;
}

void addsolution(){
	static int index = 0;
	int i;
	for (i = 0; i < 8; i++)
		solves[index][i] = '1' + A[i];
	solves[index++][8] = 0;
}

void init(int i){
	for (A[i] = 0; A[i] < 8; A[i]++){
		if (isntOk(i)) continue;
		if (i < 7) init(i + 1);
		if (i == 7) addsolution();
	}
}

int main(){
	int i, j, k, l, n;
	long N;
	scanf("%ld", &N);
	init(0);

	while (N--){
		scanf("%d%d", &j, &k);
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		for (i = n = 0; i < 92; i++){
			if (solves[i][k-1] == j - 1 + '1'){
				printf("%2d     ", ++n);
				for (l = 0; l < 8; l++) printf(" %c", solves[i][l]);
				printf("\n");
			}
		}
		if (N) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
