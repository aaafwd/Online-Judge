/* @JUDGE_ID: 19899RK 10684 C++ "By Anadan" */
// The jackpot
// Accepted (0.215 seconds using as much as 392 kbytes)

#include <stdio.h>

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != '-' && (x < '0' || x > '9'));
	if (x == '-'){
		sgn = 1;
		x = getchar();
	}

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
	if (sgn) x = -x;
}

int main(){
	int N, x, min, max, sum;

	while (scanf("%d", &N) == 1 && N){
		scanf("%d", &x);
		min = max = sum = x;
		for (--N; N--;){
			myscanf(x); sum += x;
			if (min > sum) min = sum;
			if (max < sum - min) max = sum - min;
		}

		if (max <= 0) puts("Losing streak.");
		else printf("The maximum winning streak is %d.\n", max);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
