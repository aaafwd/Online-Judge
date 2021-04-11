/* @JUDGE_ID: 19899RK 547 C++ "By Anadan" */ 
// DDF
// Accepted (0.705 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <math.h>
#define SZ 3001

int ddf[SZ];

int getdigitsum(int n){
	int res = 0;

	while (n){
		res += n % 10;
		n /= 10;
	}

	return res;
}

int getsum(int n){
	int i, toi = (int)sqrt(n), res = 1 + getdigitsum(n);

	for (i = 2; i <= toi; ++i){
		if (!(n % i)){
			res += getdigitsum(i);
			res += getdigitsum(n / i);
		}
	}

	if (toi * toi == n) res -= getdigitsum(toi);
	return res;
}

void setddf(int n){
	int stack[100], sp = 0, tmp;

	while (1){
		if (ddf[n] != -1) break;
		tmp = getsum(n);
		if (tmp == n) break;
		stack[sp++] = n;
		n = tmp;
	}

	if (ddf[n] == -1) ddf[n] = 1;
	tmp = ddf[n];
	while (sp--) ddf[stack[sp]] = ++tmp;
}

int main(){
	int set = 0, n, m, i, max, num, tmp;

	for (i = 0; i < SZ; ++i) ddf[i] = -1;
	for (i = 0; i < SZ; ++i) setddf(i);

	while (scanf("%d%d\n", &n, &m) == 2){
		printf("Input%d: %d %d\n", ++set, n, m);
		if (n > m) n ^= m ^= n ^= m;
		printf("Output%d:", set);

		num = n;
		max = ddf[n];
		for (i = n + 1; i <= m; ++i){
			tmp = ddf[i];
			if (max < tmp){
				max = tmp;
				num = i;
			}
		}

		while (1){
			printf(" %d", num);
			tmp = getsum(num);
			if (tmp == num) break;
			num = tmp;
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
