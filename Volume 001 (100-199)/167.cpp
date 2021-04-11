/* @JUDGE_ID: 19899RK 167 C++ "By Anadan" */
// The Sultan's Successors
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char solves[92][8], A[8];

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
	for (int i = 0; i < 8; i++) solves[index][i] = A[i];
	index++;
}

void init(int i){
	for (A[i] = 0; A[i] < 8; A[i]++){
		if (isntOk(i)) continue;
		if (i < 7) init(i + 1);
		if (i == 7) addsolution();
	}
}

int main(){
	int i, j, s, max, N, tmp[8][8];

	init(0);
	scanf("%d", &N);
	while (N--){
		for (i = 0; i < 8; i++) for (j = 0; j < 8; j++){
			scanf("%d", &tmp[i][j]);
		}
		for (i = max = 0; i < 92; i++){
			for (j = s = 0; j < 8; j++){
				s += tmp[j][solves[i][j]];
			}
			if (s > max) max = s;
		}
		printf("%5d\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
