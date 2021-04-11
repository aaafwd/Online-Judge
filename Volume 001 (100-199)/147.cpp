/* @JUDGE_ID: 19899RK 147 C++ "By Anadan" */
// Dollars
// Accepted (0.023 seconds with low memory spent)

#include <stdio.h>
#define SZ 6001

unsigned long long solves[SZ];

int myscanf(int &x, int &y){
	int i;

	while ((x = getchar()) < '0' || x > '9');

	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9'){
		x = x * 10 + i - '0';
	}

	y = (getchar() - '0') * 10 + getchar() - '0';

	return (100 * x + y) / 5;
}

int main(){
	int notes[11] = { 2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1 };
	int i, j, k;

	solves[0] = 1;
	for (i = 0; i < 11; i++){
		j = notes[i];
		for (k = j; k < SZ; k++) solves[k] += solves[k-j];
	}

	while (1){
		k = myscanf(i, j);
		if (k == 0) break;
		printf("%3d.%02d%17llu\n", i, j, solves[k]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
