/* @JUDGE_ID: 19899RK 10419 C++ "By Anadan" */ 
// Sum-up the Primes
// Accepted (0.936 seconds using as much as 388 kbytes)

#include <stdio.h>

int T, curr[15];
const int primes[62] = {
	101, 103, 107, 109, 11, 113, 127, 13, 131, 137, 139, 149, 151, 157,
	163, 167, 17, 173, 179, 181, 19, 191, 193, 197, 199, 2, 211, 223,
	227, 229, 23, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
	29, 293, 3, 31, 37, 41, 43, 47, 5, 53, 59, 61, 67, 7, 71, 73, 79,
	83, 89, 97
};
const int min[15] = { 1, 2, 4, 7, 10, 15, 20, 27, 34, 45, 56, 69, 82, 99, 116 };
const int max[15] = { 0, 293, 586, 869, 1152, 1433, 1714, 1991, 2268, 2539, 2810, 3079, 3348, 3611, 3874 };

int generate(int N, int t, int i, int f){
	if (N == 0){
		if (t == T){
			printf("%d", curr[0]);
			for (i = 1; i < T; ++i) printf("+%d", curr[i]);
			putchar('\n');
			return 1;
		}

		return 0;
	}

	if (N < min[T - t] || N > max[T - t]) return 0;
	if (i > 26 && ((N & 1) ^ ((T - t) & 1))) return 0;

	if (N >= primes[i]){
		if (f > 1 || (f == 1 && primes[i] == 2)) { ++i; f = 0; }
		curr[t] = primes[i];
		if (generate(N - primes[i], t + 1, i, f + 1)) return 1;
	}

	for (++i; i < 62; ++i){
		if (N < primes[i]) continue;
		curr[t] = primes[i];
		if (generate(N - primes[i], t + 1, i, 1)) return 1;
	}

	return 0;
}

int main(){
	int set = 0, i;

	while (scanf("%d%d\n", &i, &T) == 2 && i){
		printf("CASE %d:\n", ++set);
		if (!generate(i, 0, 0, 0)) printf("No Solution.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
