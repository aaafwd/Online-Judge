/* @JUDGE_ID: 19899RK 674 C++ "By Anadan" */
// Coin Change
// Accepted (0.150 seconds using as much as 416 kbytes)

#include <stdio.h>

int main(){
	int notes[5] = { 50, 25, 10, 5, 1 };
	int i, j, k;
	long solves[7490];

	for (i = 0; i < 7490; i++) solves[i] = 0; solves[0] = 1;
	for (i = 0; i < 5; i++){
		j = notes[i];
		for (k = j; k < 7490; k++) solves[k] += solves[k-j];
	}

	while (scanf("%d", &k) > 0){
		printf("%ld\n", solves[k]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
