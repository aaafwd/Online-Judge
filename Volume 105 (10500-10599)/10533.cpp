/* @JUDGE_ID: 19899RK 10533 C++ "By Anadan" */
// Digit Primes
// Accepted (1.764 seconds using as much as 1488 kbytes)

#include <stdio.h>

int dprimes[30200], dp;
char seeve[1000000] = { 0 };

int getdigitsum(int a){
	int res = 0;

	while (a){
		res += a % 10;
		a /= 10;
	}

	return res;
}

int main(){
	int i, j, k, set, l, r, m;

	seeve[0] = seeve[1] = 1;
	for (i = 2; i < 1000000; ++i){
		if (seeve[i]) continue;
		for (j = i + i; j < 1000000; j += i) seeve[j] = 1;
	}

	dp = 0;
	for (i = 2; i < 1000000; ++i){
		if (seeve[i]) continue;
		k = getdigitsum(i);
		if (!seeve[k]) dprimes[dp++] = i;
	}

	scanf("%d", &set);
	while (set--){
		while ((i = getchar()) < '0' || i > '9'); i -= '0';
		while ((k = getchar()) >= '0' && k <= '9'){
			i = 10 * i + k - '0';
		}

		while ((j = getchar()) < '0' || j > '9'); j -= '0';
		while ((k = getchar()) >= '0' && k <= '9'){
			j = 10 * j + k - '0';
		}

		l = 0; r = dp - 1;
		while (l + 1 < r){
			m = (l + r) >> 1;
			if (dprimes[m] > i) r = m; else l = m;
		}
		while (l >= 0 && dprimes[l] >= i) --l;
		i = l + 1;

		l = 0; r = dp - 1;
		while (l + 1 < r){
			m = (l + r) >> 1;
			if (dprimes[m] > j) r = m; else l = m;
		}
		while (l < dp && dprimes[l] <= j) ++l;
		j = l - 1;

		printf("%d\n", j - i + 1);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
