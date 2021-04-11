/* @JUDGE_ID: 19899RK 10396 C++ "By Anadan" */
// Vampire Numbers
// Accepted (18.734 seconds using as much as 448 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int vampire4[3], N4;
int vampire6[1000], N6;
int vampire8[10000], N8;

int suitable(long i, long j){
	char mask[10];
	long k = i * j;

	memset(mask, 0, 10);
	while (k){
		mask[k % 10]++;
		k /= 10;
	}

	while (i){
		k = i % 10;
		if (--mask[k] < 0) return 0;
		i /= 10;
	}

	while (j){
		k = j % 10;
		if (--mask[k] < 0) return 0;
		j /= 10;
	}

	return 1;
}

int sort_function(const void *a, const void *b){
	if (*(long *)a < *(long *)b) return -1;
	return 1;
}

void init(){
	long i, j, step;
	char flag;

	N4 = 3;
	vampire4[0] = 1260;
	vampire4[1] = 1530;
	vampire4[2] = 6880;

	N6 = N8 = 0;
	for (i = 100; i <= 999; ++i){
		if (!(i % 10)) flag = 1; else flag = 0;
		step = (i & 1) + 1;
		for (j = 100; j <= 999; j += step){
			if (flag && !(j % 10)) continue;
			if (suitable(i, j)) vampire6[N6++] = i * j;
		}
	}
	qsort(vampire6, N6, sizeof(long), sort_function);

	for (i = 1001; i <= 9999; ++i){
		if (!(i % 10)) flag = 1; else flag = 0;
		step = (i & 1) + 1;

		j = (10000000L + i - 1) / i;
		if (j < i) j = i;
		if (step == 2 && (j & 1)) ++j;

		for (; j <= 9999; j += step){
			if (flag && !(j % 10)) continue;
			if (suitable(i, j)) vampire8[N8++] = i * j;
		}
	}
	qsort(vampire8, N8, sizeof(long), sort_function);
}

int main(){
	int n, i, *p;

	init();
	while (scanf("%d\n", &n) == 1){
		if (n == 4) n = N4, p = vampire4;
		else if (n == 6) n = N6, p = vampire6;
		else if (n == 8) n = N8, p = vampire8;
		else return 1;

		printf("%d\n", p[0]);
		for (i = 1; i < n; ++i){
			if (p[i] != p[i - 1]) printf("%d\n", p[i]);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
