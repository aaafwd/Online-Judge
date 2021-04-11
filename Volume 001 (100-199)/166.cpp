/* @JUDGE_ID: 19899RK 166 C++ "By Anadan" */
// Making Change
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

const int denom[6] = { 1, 2, 4, 10, 20, 40 };
int coins[6], mincoins[141], min, price;

void generate(int i, int cur, int c_coins){
	if (c_coins >= min) return;
	if (cur >= price && min > c_coins + mincoins[cur - price]){
		min = c_coins + mincoins[cur - price];
	}

	for (; i >= 0; --i){
		if (coins[i]){
			--coins[i];
			generate(i, cur + denom[i], c_coins + 1);
			++coins[i];
		}
	}
}

int main(){
	int i, j;

	mincoins[0] = 0;
	for (i = 1; i < 101; ++i) mincoins[i] = 101;
	for (i = 0; i < 101; ++i) for (j = 0; j < 6; ++j){
		if (mincoins[i + denom[j]] > mincoins[i] + 1) mincoins[i + denom[j]] = mincoins[i] + 1;
	}

	while (1){
		for (min = i = 0; i < 6; ++i){
			scanf("%d", coins + i);
			if (coins[i]) min = 1;
		}

		if (min == 0) break;
		min = 220;
		scanf("%d.%d\n", &i, &price);
		price = i * 20 + price / 5;

		generate(5, 0, 0);
		printf("%3d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
