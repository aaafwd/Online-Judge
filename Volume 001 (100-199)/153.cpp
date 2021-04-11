/* @JUDGE_ID: 19899RK 153 C++ "By Anadan" */
// Permalex
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char mask[26], str[32];
const int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
int powers[10];

int getpermutation(int len){
	int i, j, k;

	memset(powers, 0, sizeof(powers));
	for (i = 2; i <= len; ++i){
		k = i;
		for (j = 0; k != 1; ++j){
			while (!(k % primes[j])){
				k /= primes[j];
				++powers[j];
			}
		}
	}

	for (i = 0; i < 26; ++i){
		for (len = 2; len <= mask[i]; ++len){
			k = len;
			for (j = 0; k != 1; ++j){
				while (!(k % primes[j])){
					k /= primes[j];
					--powers[j];
				}
			}
		}
	}

	k = 1;
	for (i = 0; i < 10; ++i){
		while (powers[i]--) k *= primes[i];
	}

	return k;
}

int countpermalex(){
	int i = 0, j, n, res = 1, len = strlen(str) - 1;

	for (n = 0; str[n]; ++n){
		for (; mask[i] == 0; ++i);
		if (str[n] != 'a' + i){
			for (j = 0; j < str[n] - 'a'; ++j){
				if (mask[j] == 0) continue;
				--mask[j];
				res += getpermutation(len - n);
				++mask[j];
			}
		}

		--mask[str[n] - 'a'];
	}

	return res;
}

int main(){
	int i;

	while (scanf("%s", str) == 1 && str[0] != '#'){
		memset(mask, 0, sizeof(mask));
		for (i = 0; str[i]; ++i) ++mask[str[i] - 'a'];
		printf("%10d\n", countpermalex());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
