/* @JUDGE_ID: 19899RK 10329 C++ "By Anadan" */ 
// Combinatorial Expression
// Accepted (0.275 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <string.h>
#include <math.h>

int primes[700], power[700], P;

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void mul(int N){
	int i, k;

	for (i = 0; i < P; ++i){
		k = N;
		while (k >= primes[i]){
			k /= primes[i];
			power[i] += k;
		}
	}
}

void div(int N){
	int i, k;

	for (i = 0; i < P; ++i){
		k = N;
		while (k >= primes[i]){
			k /= primes[i];
			power[i] -= k;
		}
	}
}

void strmul(char *s, int N){
	int rest = 0;

	while (*s){
		rest += N * (*s - '0');
		*s++ = '0' + (rest % 10);
		rest /= 10;
	}

	while (rest){
		*s++ = '0' + (rest % 10);
		rest /= 10;
	}

	*s = 0;
}

int main(){
	int N, M, i, j;
	char num[110];
	double tmp;

	primes[0] = 2;
	for (P = 1, i = 3; i < 5000; i += 2){
		for (j = 0; j < P; ++j) if (!(i % primes[j])) break;
		if (j == P) primes[P++] = i;
	}

	while (scanf("%d%d\n", &M, &N) == 2){
		memset(power, 0, sizeof(power));
		while (M--){
			scanf("%d%d\n", &i, &j);
			mul(i); div(j); div(i - j);
		}
		while (N--){
			scanf("%d%d\n", &i, &j);
			div(i); mul(j); mul(i - j);
		}

		for (i = 0; i < P; ++i) if (power[i] < 0) break;
		if (i < P) printf("0\n");
		else{
			tmp = 0.0;
			for (i = 0; i < P; ++i){
				if (power[i]) tmp += log10(primes[i]) * power[i];
			}

			N = int(floor(tmp)) + 1;
			if (N < 101){
				num[0] = '1'; num[1] = 0;
				for (i = 0; i < P; ++i){
					while (power[i]--) strmul(num, primes[i]);
				}
				_reverse(num);
				printf("%s\n", num);

			}else printf("-1\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
