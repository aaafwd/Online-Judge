/* @JUDGE_ID: 19899RK 102 C++ "By Anadan" */
// Ecological Bin Packing
// Accepted (0.190 seconds using as much as 388 kbytes)

#include <stdio.h>

long bgc[3][3], max;
char outp[4];

void func(int i, int j, int k){
	long tmp = bgc[0][i] + bgc[1][j] + bgc[2][k];
	if (tmp > max){
		max = tmp;
		outp[0] = "BGC"[i]; outp[1] = "BGC"[j]; outp[2] = "BGC"[k];
	}
}

int main(){
	long sum;
	int i, j;

	outp[3] = 0;
	while (1){
		sum = max = 0L;
		for (i = 0; i < 3; i++) for (j = 0; j < 3; j++){
			if (scanf("%ld", &bgc[i][j]) <= 0) return 0;
			sum += bgc[i][j];
		}
		func(0, 2, 1); func(0, 1, 2);
		func(2, 0, 1); func(2, 1, 0);
		func(1, 0, 2); func(1, 2, 0);
		printf("%s %ld\n", outp, sum - max);
	}
}
/* @END_OF_SOURCE_CODE */
