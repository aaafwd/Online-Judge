/* @JUDGE_ID: 19899RK 10225 C++ "By Anadan" */
// Discrete Logging
// Accepted (1.070 seconds using as much as 1784 kbytes)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSZ 46342

typedef unsigned long long dword;
struct List{
	dword m, res;
}pt[MAXSZ];
dword P, B, N, M;

dword powm(dword a, dword n, dword mod){
	dword res1 = 1, res2 = a;
	while (n){
		if (n & 1){
			--n;
			res1 = (res1 * res2) % mod;
		}else{
			n >>= 1;
			res2 = (res2 * res2) % mod;
		}
	}
	return res1;
}

int try_find(dword m, dword elem){
	dword i = 0, j = M - 1, k;

	while (j > i + 1){
		k = (i + j) >> 1;
		if (elem <= pt[k].res) j = k; else i = k;
	}

	if (pt[i].res == elem){
		printf("%lu\n", M*m + pt[i].m);
		return 1;
	}
	if (pt[j].res == elem){
		printf("%lu\n", M*m + pt[j].m);
		return 1;
	}

	return 0;
}

int sort_function(const void *a, const void *b){
	List *la = (List *)a, *lb = (List *)b;
	if (la->res < lb->res) return -1;
	if (la->res == lb->res && la->m < lb->m) return -1;
	return 1;
}

int main(){
	dword i, tmp;
	while (scanf("%lu%lu%lu\n", &P, &B, &N) == 3){
		M = (dword)ceil(sqrt(P));
		pt[M - 1].res = (N * powm(B, P - M, P)) % P;
		pt[M - 1].m = M - 1;
		for (i = M - 1; i > 0; --i){
			pt[i - 1].m = i - 1;
			pt[i - 1].res = (pt[i].res * B) % P;
		}

		qsort((void *)pt, M, sizeof(List), sort_function);
		if (try_find(0, 1)) continue;
		N = powm(B, M, P);
		for (tmp = i = 1; i < M; ++i){
			tmp = (tmp * N) % P;
			if (try_find(i, tmp)) break;
		}

		if (i == M) printf("no solution\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
