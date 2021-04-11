/* @JUDGE_ID: 19899RK 10447 C++ "By Anadan" */ 
// Sum-up the Primes (II)
// Accepted (1.803 seconds using as much as 392 kbytes)

#include <stdio.h>

int T, curr[15];
const int ordered[62] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
	67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
	139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
	223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293
};
const int primes[62] = {
	101, 103, 107, 109, 11, 113, 127, 13, 131, 137, 139, 149, 151, 157,
	163, 167, 17, 173, 179, 181, 19, 191, 193, 197, 199, 2, 211, 223,
	227, 229, 23, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
	29, 293, 3, 31, 37, 41, 43, 47, 5, 53, 59, 61, 67, 7, 71, 73, 79,
	83, 89, 97
};
const int pos[62] = { 25, 44, 50, 55, 4, 7, 16, 20, 30, 42, 45, 46, 47, 48,
	49, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 0, 1, 2, 3, 5, 6, 8, 
	9, 10, 11, 12, 13, 14, 15, 17, 18, 19, 21, 22, 23, 24, 26, 27, 28, 
	29, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 43
};
int freq[62], min[13], max[13];

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

	for (; i < 62; ++i){
		if (N < primes[i] || f >= freq[i]){
			f = 0;
			continue;
		}
		curr[t] = primes[i];
		if (generate(N - primes[i], t + 1, i, f + 1)) return 1;
		f = 0;
	}

	return 0;
}

int main(){
	int set = 0, i, j, t, query, B, Q;

	scanf("%d\n", &B);
	for (set = 1; set <= B; ++set){
		printf("Block %d:\n", set);

		freq[pos[0]] = 1;
		for (i = 1; i < 62; ++i) scanf("%d", &freq[pos[i]]);

		min[0] = max[0] = 0;
		for (t = 1; t <= 12; ++t){
			min[t] = 5000; max[t] = -1;
		}

		for (i = 61, j = t = 1; i >= 0 && t <= 12; ++t){
			if (freq[pos[i]] >= j) max[t] = max[t - 1] + ordered[i], ++j;
			else --i, --t, j = 1;
		}

		for (i = 0, j = t = 1; i < 62 && t <= 12; ++t){
			if (freq[pos[i]] >= j) min[t] = min[t - 1] + ordered[i], ++j;
			else ++i, --t, j = 1;
		}
		min[0] = 1;

		scanf("%d\n", &Q);
		for (query = 1; query <= Q; ++query){
			printf("Query %d:\n", query);
			scanf("%d%d%d\n", &i, &T, &freq[pos[0]]);
			if ((((i & 1) ^ (T & 1)) && freq[pos[0]] == 0) || !generate(i, 0, 0, 0)){
				printf("No Solution.\n");
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
