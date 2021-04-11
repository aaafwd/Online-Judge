/* @JUDGE_ID: 19899RK 10578 C++ "By Anadan" */
// Problem D: The Game of 31
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#define SZ 15625

char res[SZ];

int win(int x){
	int i, j, sum = 0;

	if (res[x] != 2) return res[x];
	for (j = x, i = 0; i < 6; ++i, j /= 5){
		sum += (j % 5) * (i + 1);
	}

	sum = 84 - sum;
	if (sum > 31){
		res[x] = 1;
		return 1;
	}
	else if (sum == 31){
		res[x] = 0;
		return 0;
	}

	res[x] = 0;
	for (sum = 1, j = x, i = 0; i < 6; ++i, j /= 5, sum *= 5){
		if (!(j % 5)) continue;
		if (!win(x - sum)){
			res[x] = 1;
			break;
		}
	}

	return res[x];
}

int main(){
	int i, j, k, x, arr[6];
	char str[100];

	for (i = 0; i < SZ; ++i) res[i] = 2;

	while (scanf("%s", str) == 1){
		for (i = 0; i < 6; ++i) arr[i] = 4;
		for (i = 0; str[i]; ++i) --arr[str[i] - '1'];

		for (k = 1, x = j = 0; j < 6; ++j, k *= 5){
			x += arr[j] * k;
		}

		i &= 1;
		if (!win(x)) i ^= 1;

		printf("%s %c\n", str, "AB"[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
