/* @JUDGE_ID: 19899RK 357 C++ "By Anadan" */
// Let Me Count The Ways
// Accepted (0.035 seconds with low memory spent)

#include<stdio.h>

long long res[30001];
const int coins[] = { 1, 5, 10, 25, 50 };

int main(){
	int i, j;

	res[0] = 1;
	for (j = 0; j < 5; ++j) for (i = coins[j]; i <= 30000; ++i){
		res[i] += res[i - coins[j]];
	}

	while (scanf("%d", &i) == 1){
		if (res[i] == 1) printf("There is only 1 way to produce %d cents change.\n", i);
		else printf("There are %lld ways to produce %d cents change.\n", res[i], i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
