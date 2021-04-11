/* @JUDGE_ID: 19899RK 344 C++ "By Anadan" */
// Roman Digititis
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

void toRoman(int n, int *s){
	s[0] = s[1] = s[2] = s[3] = s[4] = 0;

	while (n){
		if (n >= 100) n -= 100, ++s[4];
		else if (n >= 90) n -= 90, ++s[2], ++s[4];
		else if (n >= 50) n -= 50, ++s[3];
		else if (n >= 40) n -= 40, ++s[2], ++s[3];
		else if (n >= 10) n -= 10, ++s[2];
		else if (n >= 9) n -= 9, ++s[0], ++s[2];
		else if (n >= 5) n -= 5, ++s[1];
		else if (n >= 4) n -= 4, ++s[0], ++s[1];
		else s[0] += n, n = 0;
	}
}

int main(){
	int n;
	int solves[101][5], tmp[5];
	solves[0][0] = solves[0][1] = solves[0][2] = solves[0][3] = solves[0][4] = 0;

	for (n = 1; n <= 100; n++){
		toRoman(n, tmp);
		solves[n][0] = solves[n-1][0] + tmp[0];
		solves[n][1] = solves[n-1][1] + tmp[1];
		solves[n][2] = solves[n-1][2] + tmp[2];
		solves[n][3] = solves[n-1][3] + tmp[3];
		solves[n][4] = solves[n-1][4] + tmp[4];
	}

	while (scanf("%d", &n) > 0){
		if (n == 0) break;
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, solves[n][0], solves[n][1], solves[n][2], solves[n][3], solves[n][4]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
