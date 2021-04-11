/* @JUDGE_ID: 19899RK 10201 C++ "By Anadan" */
// Adventures in Moving - Part IV
// Accepted (0.290 seconds using as much as 396 kbytes)

#include <stdio.h>

int myscanf(long *k, long *p){
	int c;

	*k = 0;
	while ((c = getchar()) != '\n' && c != -1) if (('0' <= c) && (c <= '9')) break;
	if (c == '\n' || c == -1) return 0;
	do{
		*k *= 10;
		*k += c - '0';
		c = getchar();
	}while (('0' <= c) && (c <= '9'));

	if (p){
		*p = 0;
		while ((c = getchar()) != '\n' && c != -1) if (('0' <= c) && (c <= '9')) break;
		if (c == '\n' || c == -1) return 0;
		do{
			*p *= 10;
			*p += c - '0';
			c = getchar();
		}while (('0' <= c) && (c <= '9'));
	}

	while (c != '\n') c = getchar();
	return 1;
}

int main(){
	long set, S, passed, i, j, k, p, c, tmp, minprice[2][201];

	scanf("%ld\n\n", &set);
	while (set--){
		myscanf(&S, NULL);

		for (k = 0; k < 201; ++k) minprice[0][k] = -1;
		minprice[0][100] = 0;
		c = passed = 0;
		while (myscanf(&k, &p)){
			c ^= 1;
			for (i = 0; i < 201; ++i) minprice[c][i] = -1;
			for (i = k - passed; i < 201; ++i){
				if (minprice[c ^ 1][i] == -1) continue;
				for (j = i - k + passed; j < 201; ++j){
					tmp = minprice[c ^ 1][i] + (j - i + k - passed) * p;
					if (minprice[c][j] == -1 || minprice[c][j] > tmp)
						minprice[c][j] = tmp;
				}
			}
			passed = k;
		}

		tmp = -1;
		for (i = 100 + S - passed; i < 201; ++i){
			if (minprice[c][i] == -1) continue;
			if (tmp == -1 || tmp > minprice[c][i])
				tmp = minprice[c][i];
		}

		if (tmp == -1) printf("Impossible\n");
		else printf("%ld\n", tmp);

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
