/* @JUDGE_ID: 19899RK 10541 C++ "By Anadan" */
// Stripe
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

void _reverse(char *p){
	char *q = p + strlen(p) - 1;
	while (p < q) *p++ ^= *q-- ^= *p ^= *q;
}

void mul(char *sav, int n, int k){
	int rest = 0;
	char *p = sav;

	while (*p){
		rest += (*p - '0') * n;
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	while (rest){
		*p++ = (rest % 10) + '0';
		rest /= 10;
	}

	*p-- = 0;
	for (rest = 0; p >= sav; --p){
		rest = 10 * rest + *p - '0';
		*p = (rest / k) + '0';
		rest %= k;
	}
}

void add(char *p, char *q){
	int rest = 0;

	while (*p && *q){
		rest += *p - '0' + *q - '0';
		*p = (rest % 10) + '0';
		rest /= 10;
		++p; ++q;
	}

	while (*p){
		rest += *p - '0';
		*p = (rest % 10) + '0';
		rest /= 10;
		++p;
	}

	while (*q){
		rest += *q - '0';
		*p = (rest % 10) + '0';
		rest /= 10;
		++p; ++q;
	}

	if (rest) *p++ = '1';
	*p = 0;
}

int main(){
	int set, N, K, sum, i, j;
	char res[80], curr[80], *p;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &K);
		sum = 0;
		for (i = 0; i < K; ++i){
			scanf("%d", &j);
			sum += j;
			if (i) ++sum;
		}

		if (sum == 0) puts("1");
		else if (sum > N) puts("0");
		else{
			N -= sum - 1;
			strcpy(res, "1");
			strcpy(curr, "1");
			for (i = 0, --K; --N;){
				mul(curr, ++K, ++i);
				add(res, curr);
			}

			_reverse(res);
			for (p = res; *p == '0'; ++p);
			puts(*p ? p : "0");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
