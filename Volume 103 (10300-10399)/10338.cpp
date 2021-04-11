/* @JUDGE_ID: 19899RK 10338 C++ "By Anadan" */
// Mischievous Children
// Accepted (0.186 seconds using as much as 384 kbytes)

#include <stdio.h>
#include <string.h>

typedef unsigned long dword;
const int tot_primes = 8;
const int primes[tot_primes] = { 2, 3, 5, 7, 11, 13, 17, 19 };
int powers[tot_primes];

void mult(int n){
	switch (n){
	case 2: ++powers[0]; break;
	case 3: ++powers[1]; break;
	case 4: powers[0]+=2; break;
	case 5: ++powers[2]; break;
	case 6: ++powers[0], ++powers[1]; break;
	case 7: ++powers[3]; break;
	case 8: powers[0]+=3; break;
	case 9: powers[1]+=2; break;
	case 10: ++powers[0], ++powers[2]; break;
	case 11: ++powers[4]; break;
	case 12: powers[0]+=2, ++powers[1]; break;
	case 13: ++powers[5]; break;
	case 14: ++powers[0], ++powers[3]; break;
	case 15: ++powers[1], ++powers[2]; break;
	case 16: powers[0]+=4; break;
	case 17: ++powers[6]; break;
	case 18: ++powers[0], powers[1]+=2; break;
	case 19: ++powers[7]; break;
	case 20: powers[0]+=2, ++powers[2]; break;
	}
}

void divv(int n){
	switch (n){
	case 2: --powers[0]; break;
	case 3: --powers[1]; break;
	case 4: powers[0]-=2; break;
	case 5: --powers[2]; break;
	case 6: --powers[0], --powers[1]; break;
	case 7: --powers[3]; break;
	case 8: powers[0]-=3; break;
	case 9: powers[1]-=2; break;
	case 10: --powers[0], --powers[2]; break;
	case 11: --powers[4]; break;
	case 12: powers[0]-=2, --powers[1]; break;
	case 13: --powers[5]; break;
	case 14: --powers[0], --powers[3]; break;
	case 15: --powers[1], --powers[2]; break;
	case 16: powers[0]-=4; break;
	case 17: --powers[6]; break;
	case 18: --powers[0], powers[1]-=2; break;
	case 19: --powers[7]; break;
	case 20: powers[0]-=2, --powers[2]; break;
	}
}

int main(){
	dword res;
	int set, dataset, i, j;
	char str[21], letters[26];

	scanf("%d\n", &set);
	for (dataset = 1; dataset <= set; ++dataset){
		scanf("%s\n", str);
		memset(letters, 0, 26);
		memset(powers, 0, tot_primes * sizeof(int));
		for (i = 0; str[i]; ++i){
			++letters[str[i] - 'A'];
			if (letters[str[i] - 'A'] > 1) divv(int(letters[str[i] - 'A']));
		}

		for (j = 2; j <= i; ++j) mult(j);

		res = 1;
		for (j = 0; j < tot_primes; ++j){
			while (powers[j]--) res *= primes[j];
		}

		printf("Data set %d: %lu\n", dataset, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
